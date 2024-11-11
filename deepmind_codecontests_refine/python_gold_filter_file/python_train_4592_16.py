t = int(input())

def f(n):
  if n % 2 == 0:
    return False

  i = 3
  while i * i <= n:
    if n % i == 0:
      return False
    i += 2

  return True

for _ in range(t):
  a, b = map(int, input().split())
  if a - b == 1:
    if f((2 * b) + 1):
      print("YES")
      continue
  print("NO")