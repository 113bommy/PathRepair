from math import gcd
n = int(input())
a = list(map(int,input().split()))
p = a[0]
for i in range(1,n):
    p = gcd(p,a[i])
print(p)