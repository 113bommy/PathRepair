n,k = map(int, input().split())
g = [[0]*(k+1) for _ in range(k+1)]
ans,b = 0,0
for _ in range(n):
  x,y,c = input().split()
  x,y = int(x), int(y)
  d = x//k + y//k
  x %= k; y %= k
  if (c == 'W') ^ (d%2):
    g[x+1][y+1] += 1
  else:
    g[x+1][y+1] -= 1
    b += 1
for i in range(k):
  for j in range(k):
    g[i+1][j+1] += g[i][j+1] + g[i+1][j] - g[i][j]
for i in range(k):
  for j in range(k):
    cur = g[k][k] - g[k][j] - g[i][k] + g[i][j]*2 + b
    if cur > ans: ans = cur
    if n-cur > ans: ans = n-cur
print(ans)