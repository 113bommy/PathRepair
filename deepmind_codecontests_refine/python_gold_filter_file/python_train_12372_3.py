n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]

ans = 0
cannot = 0
for i in range(n-1):
  for j in range(i+1,n):
    detour = min([A[i][k] + A[k][j] for k in range(n) if k!=i and k!=j]+[10**18])
    if detour<A[i][j]:
      cannot = 1
    elif detour>A[i][j]:
      ans += A[i][j]
if cannot:
  print(-1)
else:
  print(ans)
