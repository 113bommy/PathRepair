import math

n = int(input())
k = 1
while n % k == 0:
    k *= 3

print(n // k + 1)