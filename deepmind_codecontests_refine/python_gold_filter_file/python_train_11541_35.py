import math

A,B,C=map(int,input().split())
x=math.gcd(A,B)

if C%x==0:
    print("YES")
else:
    print("NO")
