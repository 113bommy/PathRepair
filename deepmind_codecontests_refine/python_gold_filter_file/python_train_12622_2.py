from math import ceil
sInt = lambda: int(input())
mInt = lambda: map(int, input().split())
lInt = lambda: list(map(int, input().split()))

t= sInt()

for _ in range(t):
    x1,y1,x2,y2= mInt()

    if x1==x2 or y1==y2:
        print(1)
    else:
        if x1>y1:
            x1,y1=y1,x1
            x2,y2=y2,x2
        print((y2-y1)*(x2-x1)+1)


