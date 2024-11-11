n, m = map(int, input().split())
l = [0]*m
for i in range(m):
  a, b = map(int, input().split())
  l[i] = [b, a]
l.sort()

ans = 0
x = 0
for i in range(m):
  if x < l[i][1]:
    ans += 1
    x = l[i][0] -1
print(ans)