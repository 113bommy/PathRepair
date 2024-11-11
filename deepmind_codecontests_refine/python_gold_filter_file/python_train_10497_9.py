n, k = map(int, input().split())
X, Y, C = [], [], []
for _ in range(n):
  x, y, c = input().split()
  X.append(int(x)%(2*k))
  Y.append(int(y)%(2*k))
  C.append(c=="B")
G = [[0]*k for _ in range(k)]
cnt = 0
for x, y, c in zip(X, Y, C):
  if (x >= k and y < k) or (x < k and y >= k):
    x += k
    c ^= 1
  x %= k
  y %= k
  G[x][y] += (-1)**c
  cnt += c
for i in range(k):
  for j in range(k-1):
    G[i][j+1] += G[i][j]
for j in range(k):
  for i in range(k-1):
    G[i+1][j] += G[i][j]
ans = 0
for i in range(k):
  for j in range(k):
    temp = G[k-1][k-1] - G[i][k-1] - G[k-1][j] + G[i][j]*2 + cnt
    ans = max(ans, temp, n-temp)
print(ans)