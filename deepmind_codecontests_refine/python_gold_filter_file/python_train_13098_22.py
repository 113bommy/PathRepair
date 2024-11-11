from heapq import heappush as pu, heappop as po

n,m,s,t = map(int,input().split())
e = [[] for i in range(n+1)]
for i in range(m):
    u,v,a,b = map(int,input().split())
    e[u].append((v,a,b))
    e[v].append((u,a,b))

def dik(s,v):
    S = [float("INF")]*(n+1)
    S[s] = 0
    h = []
    pu(h,[0,s])
    while h:
        d,now = po(h)
        for nex in e[now]:
            a,b = nex[0],nex[v]
            if d+b < S[a]:
                S[a] = d+b
                pu(h,[d+b,a])
    return S[::-1]
ans = []
cost = 10**15
now = 0
for i,j in zip(dik(s,1),dik(t,2)):
    now = max(now,cost-i-j)
    ans.append(now)
print(*ans[:-1][::-1],sep="\n")