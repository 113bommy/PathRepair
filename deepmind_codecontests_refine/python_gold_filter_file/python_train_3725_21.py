import math
A,B,H,M=map(int, input().split())
a=math.pi
b=math.cos(a*((60*H-11*M)/360))
Z=A**2+B**2-2*A*B*b
print(Z**(1/2))