import math
inp=lambda:map(int,input().split())
n,x,y=inp()
a=list(inp())
if x>y:
    print(n)
else:
    cnt=0
    for i in a:
        if i<=x: cnt+=1
    print(math.ceil(cnt/2))