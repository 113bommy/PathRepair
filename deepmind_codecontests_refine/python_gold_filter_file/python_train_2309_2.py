n = int(input())
a = [int(x) for x in input().split()]
a.sort(reverse=True)
dx = (1, 0, -1)
lst = 150002
ans = 0
for x in a:
  cur = -1
  for t in dx:
    if 0 < x + t < lst:
      cur = x + t
      break
  if cur == -1:
    continue
  lst = cur
  ans += 1
print(ans)