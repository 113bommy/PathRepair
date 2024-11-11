s, n = tuple(map(int, input().split()))
xys = [tuple(map(int, input().split())) for _ in range(n)]

def res(s):
  for xy in sorted(xys, key=lambda xy: xy[0]):
    x, y = xy
    if s <= x:
      return "NO"
    s += y
  return "YES"

print(res(s))