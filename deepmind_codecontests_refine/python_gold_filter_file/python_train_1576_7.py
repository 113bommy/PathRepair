import math
pi=22/7

n,r=list(map(int,input().split()))
angle=(2*math.pi)/n
angle=angle/2
value=r*(math.sin(angle))/(1-math.sin(angle))
print(round(value,7))
