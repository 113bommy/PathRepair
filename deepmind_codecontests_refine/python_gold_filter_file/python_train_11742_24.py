n = int(input())
ab = [list(map(int,input().split())) for _ in range(n-1)]
m = int(input())
uv = [list(map(int,input().split())) for _ in range(m)]

from collections import deque

links = [[] for _ in range(n+1)]
for ind,val in enumerate(ab):
    a,b = val
    links[a].append((ind,b))
    links[b].append((ind,a))

def bfs(start,end):
    parent = [[-1,-1] for _ in range(n+1)]
    d = deque()
    d.append(start)
    done = set()
    while(d):
        tmp = d.popleft()
        done.add(tmp)
        for i in links[tmp]:
            link_ind, j = i
            if(not j in done):
                parent[j] = [tmp,link_ind]
                d.append(j)
    route = []
    while(True):
        route.append(parent[end][1])
        end = parent[end][0]
        if(end == start):
            break
    return route[::-1]

links_key = [0] * (n-1)
for i,se in enumerate(uv):
    start,end = se
    route = bfs(start,end)
    for j in route:
        links_key[j] =(links_key[j] | 1<<i)

dp = [[0] * (2**m) for _ in range(n)]
dp[0][0] = 1

for i in range(n-1):
     for j in range(2**m):
         dp[i+1][j] += dp[i][j]
         dp[i+1][(j|links_key[i])] += dp[i][j]

print(dp[-1][-1])