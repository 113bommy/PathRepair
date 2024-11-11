import math
A,B,H,M=map(int,input().split())
c=abs(H*30-M*5.5)
k=A*A+B*B-2*A*B*math.cos(c*math.pi/180)
l=math.sqrt(k)
print(l)