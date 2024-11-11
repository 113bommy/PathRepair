t=int(input())
for i in range(t):
    n,x,t=map(int,input().split())
    if n==1:
        print(0)
    elif t<x:
        print(0)
    elif t==x:
        print(n-1)
    else:
        ans=0
        a=min(n-1,t//x)
        ans+=(n-a)*a
        f=a
        f-=1
        ans+=(f*(f+1))//2
        print(ans)