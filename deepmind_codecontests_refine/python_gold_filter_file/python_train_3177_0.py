a,b,c = [int(x) for x in input().split()]
x,y,z = [int(x) for x in input().split()]
d1,d2,d3 = a-x,b-y,c-z
pos,neg = 0,0
if d1>0: 
    pos+=d1//2
else:
    neg-=d1
if d2>0:
    pos+=d2//2
else:
    neg-=d2
if d3>0:
    pos+=d3//2
else:
    neg-=d3
if pos - neg >= 0:
    print("Yes")
else:
    print("No")