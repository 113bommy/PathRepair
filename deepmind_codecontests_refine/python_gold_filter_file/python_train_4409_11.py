def ii():
  return int(input())
def ss():
  return [x for x in input()]
def si():
  return [int(x) for x in input().split()]
def mi():
  return map(int, input().split())

a, b = mi()
s = [ss() for _ in range(a)]
key = True

for j, i in enumerate(s):
  if key:
    if i.count("*") == 1:
      key = False
      x = j
      y = i.index("*")
    elif i.count("*") == 2:
      key = False
      x = i.index("*")
      y = i[x + 1:].index("*") + x + 1
  else:
    if i.count("*") == 1:
      if i.index("*") == x:
        print(j + 1, y + 1)
      else:
        print(j + 1, x + 1)
    elif i.count("*") == 2:
      if i.index("*") == y:
        print(x + 1, i[y + 1:].index("*") + y + 2)
      else:
        print(x + 1, i.index("*") + 1)