n = int(input())
c, s, f = [0]*(n-1), [0]*(n-1), [0]*(n-1)
for i in range(n-1):
  c[i], s[i], f[i] = map(int, input().split())

for i in range(n):
  ans = 0
  for j in range(i, n-1):
    ans = c[j] + max([s[j], (1+(ans-1)//f[j])*f[j]])
  print(ans)