n, m = list(map(int, input().split()))
if n == m:
  print(0)
  exit()
h = list(map(int, input().split()))
maxi = sum(h)
f = [e for e in h]
# print(f)
for i in range(n - m - 1):
  for j in range(n - 1, i, -1):
    res = maxi
    for k in range(i, j):
      res = min(res, f[k] + max(0, h[j] - h[k]))
    f[j] = res
  # print(f)
print(min(f[n - m - 1:]))