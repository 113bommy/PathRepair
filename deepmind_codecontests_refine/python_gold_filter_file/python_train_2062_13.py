#17:11
n,m = map(int,input().split())
pre = [i for i in range(n)]
ans = n
for _ in range(m):
  x,y,z = map(int,input().split())
  x -= 1
  y -= 1
  X = [x]
  Y = [y]
  while pre[x] != x:
    X.append(x)
    x = pre[x]
  while pre[y] != y:
    Y.append(y)
    y = pre[y]
  if x != y:
    ans -= 1
    for xx in X:
      pre[xx] = y
    for yy in Y:
      pre[yy] = y
    pre[x] = y
#print(pre)
print(ans)