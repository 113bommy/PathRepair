from heapq import heappush, heappop

n,m,s,t = map(int,input().split())
e = [[] for i in range(n+1)]
for i in range(m):
    u,v,a,b = map(int,input().split())
    e[u].append((v,a,b))
    e[v].append((u,a,b))

S = [float("INF")]*(n+1)
S[s] = 0
h = []
heappush(h,[0,s])
while h:
    d,now = heappop(h)
    for nex,a,b in e[now]:
        if d+a < S[nex]:
            S[nex] = d+a
            heappush(h,[d+a,nex])
T = [float("INF")]*(n+1)
T[t] = 0
h = []
heappush(h,[0,t])
while h:
    d,now = heappop(h)
    for nex,a,b in e[now]:
        if d+b < T[nex]:
            T[nex] = d+b
            heappush(h,[d+b,nex])

ans = [0]*(n+1)
cost = 10**15
now = 0
for i in range(n,0,-1):
    now = max(now,cost-S[i]-T[i])
    ans[i] = now
for i in ans[1:]:
    print(i)