import math
n,x,y = map(int , input().split())
y = y/100

z = math.ceil(n*y) - x
print(max(0,z)) 