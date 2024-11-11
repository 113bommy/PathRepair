n,s=map(int,input().split())
v=list(map(int,input().split()))
a=sum(v)
if a<s:
    print(-1)
else:
    z=min(v)
    a-=s
    print(min(z,a//n))
