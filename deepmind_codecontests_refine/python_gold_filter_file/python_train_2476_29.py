import math
a,b,c,d=map(int,input().split())
x,y=math.ceil(a/d),math.ceil(c/b)
print("Yes" if x>=y else "No")