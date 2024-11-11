import math

def f(n,k):
      return math.factorial(n)//(math.factorial(n-k)*math.factorial(k))

n = int(input())

print(f(n,int(5)) + f(n,int(6)) + f(n,int(7)))