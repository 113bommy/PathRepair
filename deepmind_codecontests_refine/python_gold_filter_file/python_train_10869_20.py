n = int(input())
a = list(map(int, input().split()))
min_diff = 1000
x, y = 0, 1
for i in range(1, n):
  cur_diff = abs(a[i] - a[i - 1])
  if cur_diff < min_diff:
    x, y = i, i + 1
    min_diff = cur_diff
if abs(a[0] - a[-1]) < min_diff:
  x, y = 1, n
print(x, y)