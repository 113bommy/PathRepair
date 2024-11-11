import sys
r = lambda: sys.stdin.readline()

fir= int(input())


for ref in range(fir):
    n, x, y, d = map(int,r().split())
    ans = []
    if (y-x)%d==0:
        ans+=[int(abs((y-x))/d)]
        
    up_stair = int((n-x)/d)
    if (n-x)%d != 0:
        up_stair+=1
    if (y-n)%d==0:
        ans+=[int(abs((y-n))/d)+up_stair]

    down_stair = int(x/d)
    if x%d != 0:
        down_stair+=1
    if (y-1)%d==0:
        ans+=[int(abs((y-1))/d)+down_stair]
    if ans == []:
        print(-1)
    else:
        print(min(ans))

