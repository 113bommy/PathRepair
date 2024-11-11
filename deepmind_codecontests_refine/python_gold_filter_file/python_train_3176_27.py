n, t = map(int, input().split())
if t == 10:
  if n == 1:
    print(-1)
  else:
    print('10' + '0' * (n - 2))
else:
  print(str(t) + '0' * (n - 1))
