n = int(input())
F = [int(input().replace(' ',''), 2) for _ in range(n)]
P = [list(map(int, input().split())) for _ in range(n)]
ans=-10**10
for sp in range(1, 1024):
  total = 0
  for i in range(n):
    b = bin(F[i] & sp)
    total += P[i][b.count('1')]
  ans = max(ans, total)
print(ans)
