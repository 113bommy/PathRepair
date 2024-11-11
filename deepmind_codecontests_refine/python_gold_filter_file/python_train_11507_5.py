import math
n = int(input())

def f(n,x):
	return math.factorial(n) // math.factorial(x) // math.factorial(n-x)

print(f(n,5) + f(n, 6) + f(n,7))