# cook your dish here
import math as mt 
  
# Function to find the diagonal  
# of a regular polygon 
def polydiagonal(n, a):  
  
    # Side and side length cannot  
    # be negative  
    if (a < 0 and n < 0):  
        return -1
  
    # diagonal degree converted to radians  
    return  a * mt.cos((180) / n * 3.141592653589793238462643383/ 180)/mt.sin((180) / n * 3.141592653589793238462643383/ 180)
for i in range(int(input())):
    n=int(input())
    print(polydiagonal((2*n),1))