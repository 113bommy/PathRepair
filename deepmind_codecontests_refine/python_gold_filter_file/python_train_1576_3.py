import math

n,R=map(int,input().split(' '))

x=math.sin(math.pi/n)
#print(x)

y=((R*x)/(1-x))
print(y)