t = int(input())
for case in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  b = [0] * n
  for j in range(n // 2):
    b[j] = a[n - 1 - j]
    b[n - 1 - j] = -a[j]
  if n % 2:
    if a[n // 2] + a[n // 2 - 1] == 0:
      b[n // 2 - 1] = a[n // 2 + 1]
      b[n // 2] = -a[n // 2 + 1]
      b[n // 2 + 1] = -(-a[n // 2] + a[n // 2 - 1])
    else:
      b[n // 2 - 1] = b[n // 2] = a[n // 2 + 1]
      b[n // 2 + 1] = -(a[n // 2] + a[n // 2 - 1])
  print(' '.join(str(x) for x in b))