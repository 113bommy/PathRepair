from math import factorial

n = int(input()) - 1
m = factorial(2 * n) // (factorial(n) ** 2)

print(m)