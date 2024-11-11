n = int(input())
a = list(map(int, (' '.join(input()).split())))
for i in range(1, n):
  a[i] += a[i - 1]
f = 0
for i in range(n):
  summ = a[i]
  d = a[i]
  c = 1
  for j in range(i + 1, n):
    if a[j] - d == summ:
      c += 1
      d = a[j]
  if d == a[n - 1] and c > 1:
    f = 1
    break
if f == 1:
  print("YES")
else:
  print("NO")