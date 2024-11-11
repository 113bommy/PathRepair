N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
arr.sort(key=lambda l:-l[2])
 
for cx in range(101):
  for cy in range(101):
    ch = None
    for x, y, h in arr:
      t = h + abs(cx-x) + abs(cy-y)
      if h > 0:
        if ch is not None and t != ch:
          break
        ch = t
      else:
        if t < ch:
          break
    else:
      print(cx, cy, ch)
      exit()