from math import gcd
for _ in range(int(input())):
    a = int(input())
    k = a//gcd(a, 180)
    n = 180//gcd(a, 180)
    if k == n-1: print(2*n)
    else: print(n)