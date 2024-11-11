readInts=lambda: list(map(int, input().split()))
n,m=readInts()
edge=[]
for _ in range(m):
    l,f=readInts()
    if f==1:
        f=-1
    edge+=[(l,f,_)]
edge.sort()
ok=True
cnt=0;ret=[(0,0)]*m
u=2;v=3;t=2
for e in edge:
    if e[1]==-1:
        ret[e[2]]=(1,t)
        cnt+=t-2
        t+=1
    elif cnt<=0:
        ok=False
        break
    else:
        ret[e[2]]=(u,v)
        cnt-=1
        u+=1
        if u==v:
            u=2
            v+=1
if ok==False:
    print(-1)
else:
    for e in ret:
        print(*e)


