n = int(input())
a = [list(input()) for _ in range(n)]
ans = 0
for s in range(n):
  f = 1
  for i in range(n):
    if not f:
      break
    for j in range(n):
      if a[(i+s)%n][j] != a[(j+s)%n][i]:
        f = 0
        break
  if f:
    ans += n
print(ans)