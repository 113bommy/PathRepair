import math
n = int(input())

p = math.factorial(n)
print(p % (10**9 + 7))