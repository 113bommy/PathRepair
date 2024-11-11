n, m = map(int, input().split())
G = [[] for _ in range(n)]
ST = tuple(tuple(map(lambda x:int(x)-1, input().split())) for _ in range(m))
for s, t in ST:
  G[s].append(t)
#枝(s, t)を塞いだ時にそれぞれそこからあと何手かかるかを求める
def f(s, t):
  dp = [0]*n #そこからあと何手かかるかの期待値
  for i in range(n-2, -1, -1):
    temp = 0
    for v in G[i]:
      temp += dp[v]
    if i==s:
      temp -= dp[t]
      dp[i] = temp/(len(G[i])-1) + 1
    else:
      dp[i] = temp/len(G[i]) + 1
  return dp
T = f(-1, -1)
ans = T[0]
for i in range(n-1):
  if len(G[i]) == 1:
    continue
  m = 0
  t = -1
  for v in G[i]:
    if T[v] > m:
      m = T[v]
      t = v
  temp = f(i, t)[0]
  ans = min(ans, temp)
print(ans)