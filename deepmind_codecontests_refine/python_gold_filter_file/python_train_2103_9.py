for _ in range(int(input())):
  a, b, c, d, k = map(int, input().split())
  x, y = 0, 0
  if a <= c:
    x = 1
  else:
    if a % c == 0:
      x += a // c
    else:
      x += (a // c) + 1

  if b <= d:
    y = 1
  else:
    if b % d == 0:
      y += b // d
    else:
      y += (b // d) + 1
  
  if x + y <= k:
    print(x, y)
  else:
    print(-1)