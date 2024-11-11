import heapq as hq
n,m,s = list(map(int,input().split()))
G = [[] for _ in range(n)]

for i in range(m):
  u,v,A,B = list(map(int,input().split()))
  u -= 1
  v -= 1
  hq.heappush(G[u], (B,A,v))
  hq.heappush(G[v], (B,A,u))
  #G[u].append((B,A,v))
  #G[v].append((B,A,u))

c = [0]*n
d = [0]*n
for i in range(n):
  C,D = list(map(int,input().split()))
  c[i] = C
  d[i] = D

inf = 1<<61
M = 50*51
if s > M:s = M-1
dp = [[inf] * M for _ in range(n)] 
cur = 0
dp[cur][s] = 0
que = [(0,s,0)]
while que:
  cd,cs,cur = hq.heappop(que)
  C = c[cur];D = d[cur]
  if dp[cur][cs] < cd:continue
  if cs+C < M and cd+D < dp[cur][cs+C]:
    dp[cur][cs+C] = cd+D
    hq.heappush(que, (cd+D, cs+C, cur))
  for g in G[cur]:
    B = g[0];A = g[1];to = g[2]
    if cs >= A and B+cd < dp[to][cs-A]:
      dp[to][cs-A] = B+cd
      hq.heappush(que, (B+cd, cs-A, to))

for i in range(1,n):
  print(min(dp[i]))
