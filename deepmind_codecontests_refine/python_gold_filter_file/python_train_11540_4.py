N,M=map(int,input().split())
ab=[list(map(int,input().split())) for _ in [0]*M]
g=[set() for _ in [0]*N]
[g[b-1].add(a-1) for a,b in ab]
[g[a-1].add(b-1) for a,b in ab]
q=[i for i,gg in enumerate(g) if len(gg)==1]
cnt=0
while(q):
    cnt+=len(q)
    for i in q:
        g[i]=set()
        for j in range(N):
            g[j]=g[j]-{i}
    q=[i for i,gg in enumerate(g) if len(gg)==1]
print(min(cnt,M))