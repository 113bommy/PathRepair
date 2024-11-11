n,s=map(int,input().split())
v=list(map(int,input().split()))
if sum(v)<s:
    print(-1)
    exit()
v.sort()
a=v[0]
for i in range(n):
    s-=v[i]-a
if s<=0:
    print(a)
else:
    b=a-1-((s-1)//n)
    if b>0:
        print(b)
    else:
        print(0)