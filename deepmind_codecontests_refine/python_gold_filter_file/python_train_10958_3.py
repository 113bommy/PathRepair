import sys
# sys.setrecursionlimit(10**6) 
input=sys.stdin.readline
t=int(input())
for t1 in range(t):
    x1,y1,z1=list(map(int,input().split(" ")))
    x2,y2,z2=list(map(int,input().split(" ")))
    ans=min(z1,y2)*2
    z1-=ans//2
    y2-=ans//2
    t1=min(y1,x2)
    y1-=t1
    x2-=t1
    t1=min(y2,y1)
    y1-=t1
    y2-=t1
    ans-=min(y1,z2)*2
    print(ans)