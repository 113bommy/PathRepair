n, l = [int(x) for x in input().split()]
a = sorted([int(x) for x in input().split()])
d = max(a[0], l - a[n - 1]) * 2
for i in range(0, n - 1):
  d = max(a[i + 1] - a[i], d)
print(d / 2)