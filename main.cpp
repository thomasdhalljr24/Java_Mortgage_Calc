/* 
Here is my first program! It's a mortgage calculator. Just so you understand the math, here's the calculations: 
P * [((r+1)^m) / ((r+1)^m -1)] 
------------------------
P = Principal, 
R = interest rate (monthly): To get this, take the rate and divide it by 12 months and by 100 (because that gets you a decimal)
M = # of months (You get that by multiplying the years by 12 to convert to months)
*/

import java.text.NumberFormat;
import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    
    //STEP 1: Ask for the principal first
    System.out.println("\nHey there! What's the principal on your mortgage in USD?");
    Scanner userInput = new Scanner(System.in);
    int initialCost = userInput.nextInt();
    
    /* Now let's figure out what their interest rate is through some *fancy* math */
    System.out.println("Ok. Next step. What's the interest rate?");
    Scanner interestDiv = new Scanner(System.in);
    double interestRate = interestDiv.nextDouble();
    double interest = interestRate/1200;

    /* Now let's figure out how many months it will take to pay it off, multiply by 12 to get the months */
    System.out.println("How many years is your mortgage?");
    Scanner YOM = new Scanner(System.in);
    double yearsOnMort = YOM.nextInt();
    double monthsForMort = yearsOnMort*12;

    // Calculation time!
    double firstStep = interest*(Math.pow((1+interest),monthsForMort));
    double secondStep = (Math.pow((1+interest),monthsForMort))-1;
    double thirdStep = Math.round((firstStep/secondStep)*initialCost);

    //Now time to turn it into USD
    NumberFormat transfer = NumberFormat.getCurrencyInstance();
    String finalStep = transfer.format(thirdStep);

    System.out.println("Your monthly payment is: " + finalStep + " per month!");
    
  }
}
