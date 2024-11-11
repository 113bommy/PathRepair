import math
a,b,h,m=map(int,input().split())
q=h*30+m*0.5
w=m*6
cosa=math.cos(math.radians(q-w))
print((a**2+b**2-2*a*b*cosa)**0.5)