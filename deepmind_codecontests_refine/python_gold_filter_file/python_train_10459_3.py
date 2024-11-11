import sys
a, b = map(int, sys.stdin.readline().split())
if a < b:
  print(0)
elif a == b:
  print('infinity')
else:
  n = a - b
  if n <= b:
    print(0)
  else:
    ans = 0
    i = 1
    while i * i <= n:
      if n % i == 0:
        if i > b: ans += 1
        if n // i > b and n // i != i: ans += 1
      i += 1
    print(ans)