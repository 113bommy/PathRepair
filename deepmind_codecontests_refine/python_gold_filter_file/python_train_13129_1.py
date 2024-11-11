t = int(input())

for _ in range(t):
  n, x, y, d = map(int, input().split())
  x -= 1
  y -= 1
  if x % d == y % d:
    print(abs(x-y) // d)
  elif y % d == 0:
    ans = x // d + 1 + y // d
    if (n-1) % d == 0:
      ans = min(ans, (n-1-x) // d + 1 + (n-1-y) // d)
    print(ans)
  elif y % d == (n-1) % d:
    print((n-1-x) // d + 1 + (n-1-y) // d)
  else:
    print("-1")
