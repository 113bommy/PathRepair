import operator
import math
def c(n,k):  
    return  math.factorial(n)*math.factorial(n)//(math.factorial(k)*math.factorial(n-k)*math.factorial(n-k))
x=int(input())
print(c(x,5))
