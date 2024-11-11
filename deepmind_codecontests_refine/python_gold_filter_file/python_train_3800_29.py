import math
n,x = [int(x) for x in input().split()]
s = 0
if n<x<=n**2:
    for i in range(math.ceil(x/n),n+1):
        if x%i == 0:
            s += 1
if x<=n:
    for i in range(1,x+1):
        if x%i == 0:
            s += 1
print(s)