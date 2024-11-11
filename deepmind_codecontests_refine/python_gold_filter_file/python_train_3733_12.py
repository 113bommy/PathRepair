n=int(input())
t=list(map(int,input().split()))
m=int(input())
ans=sum(t)
for i in range(m):
    p,x=map(int,input().split())
    print(ans-t[p-1]+x)