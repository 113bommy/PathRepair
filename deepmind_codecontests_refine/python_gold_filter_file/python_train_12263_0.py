import math
n = int(input())
lx = math.ceil(n/1.08)
rx = (n+1)/1.08
print(lx if lx<rx else ':(' )