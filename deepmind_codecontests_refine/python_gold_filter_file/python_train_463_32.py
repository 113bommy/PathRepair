r,x,y,X,Y=map(int,input().split())
import math
s=((abs(X-x))**2+(abs(Y-y))**2)**.5

s=s/(2*r)
print(math.ceil(s))
