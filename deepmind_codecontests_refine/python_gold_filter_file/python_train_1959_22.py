from math import gcd
N = int(input())
A = list(map(int,input().split()))
g = 0
for a in A:
    g = gcd(a,g)
print(g)