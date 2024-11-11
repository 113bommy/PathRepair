N, *L = map(int, open(0).read().split())
cost = []
for m in zip(*[iter(L)]*N):
  cost.append(m)
ans = 0
for i in range(N):
  for j in range(i):
    for k in range(N):
      if k==i or k==j:
        continue
      if cost[i][j]>cost[i][k]+cost[k][j]:
        print(-1)
        import sys
        sys.exit()
      if cost[i][j]==cost[i][k]+cost[k][j]:
        break
    else:
      ans += cost[i][j]
print(ans)
