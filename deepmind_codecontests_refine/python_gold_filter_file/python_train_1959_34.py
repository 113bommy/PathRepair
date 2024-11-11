from math import gcd

n = int(input())
a = list(map(int, input().split()))
g = 0
for x in a:
    g = gcd(g, x)
print(g)
