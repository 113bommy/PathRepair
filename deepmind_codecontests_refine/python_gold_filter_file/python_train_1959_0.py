from math import gcd

N = int(input())
A = list(map(int,input().split()))

g = A[0]

for i in A:
    g = gcd(g,i)

print(g)
