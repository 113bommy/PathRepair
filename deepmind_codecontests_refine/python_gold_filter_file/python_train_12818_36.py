from math import ceil
n,x,y = map(int,input().split())
l = list(map(int,input().split()))
if x > y: print(n)
else:
    coun = 0
    for c in l:
        if c <= x: coun += 1
    print(ceil(coun/2))