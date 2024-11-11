# import sys
# input=sys.stdin.readline

t=int(input())
for i in range(t):
    n,x,y=list(map(int,input().split()))
    a=min(x+y-1,n)
    if x+y<n+1:
        b=1
    else:
        b=min(x+y+1-n,n)
    print(b,a)