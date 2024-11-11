from itertools import combinations
n, m, x = map(int, input().split())
ca = [list(map(int, input().split())) for _ in range(n)]

ans = 10**10
for i in range(1,n+1):
  for j in combinations(ca,i):
    check = [0]*(m+1)
    for k in j:
      for a in range(m+1):
        check[a] += k[a]
    if min(check[1:]) >= x:
      ans = min(ans, check[0])

if ans == 10**10:
  print(-1)
else:
  print(ans)