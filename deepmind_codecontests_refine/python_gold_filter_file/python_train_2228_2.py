n, m = map(int, input().split())
f = sorted(map(int, input().split()))
res = max(f) - min(f)
for i in range(m - n + 1):
  res = min(res, f[i + n - 1] - f[i])
print(res)