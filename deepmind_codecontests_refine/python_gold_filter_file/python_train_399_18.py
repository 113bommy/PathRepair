from fractions import gcd
n,x=map(int,input().split())
print(3*(n-gcd(n,x)))