import math

N = int(input())
X = math.factorial(N)
print(X % (10**9 + 7))