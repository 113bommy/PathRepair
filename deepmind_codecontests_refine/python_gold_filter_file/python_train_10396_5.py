n = int(input())
alist = list(reversed(sorted([int(input()) for _ in range(n)])))
blist = list(reversed(sorted([int(input()) for _ in range(n)])))
INF = pow(10, 9) + 7
a = alist.pop()
b = blist.pop()
aset, bset = 0, 0
ans = 1
while len(alist) > 0 or len(blist) > 0:
  if a < b:
    if bset > 0:
      ans = (ans * bset) % INF
      bset -= 1
    else:
      aset += 1
    a = INF
    if len(alist) > 0:
      a = alist.pop()
  else:
    if aset > 0:
      ans = (ans * aset) % INF
      aset -= 1
    else:
      bset += 1
    b = INF
    if len(blist) > 0:
      b = blist.pop()
print(ans % INF)
