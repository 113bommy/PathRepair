from math import ceil
n,x,y = map(int,input().split())
p = ceil((n*y)/100)
if p<x:
    print(0)
else:
    print(p-x)