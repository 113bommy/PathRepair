import math
r,x,y,a,b=map(int,input().split())
print(math.ceil(math.sqrt((a-x)*(a-x)+(b-y)*(b-y))/(2*r)))
