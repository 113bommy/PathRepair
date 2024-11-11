n,m= map(int, input().split())
par = [i for i in range(n)]

def find(x):
  if par[x] == x:
    return x
  else:
    par[x] = find(par[x])
    return par[x]

def unite(x, y):
  x = find(x)
  y = find(y)
  if x > y:
    par[x] = y
    find(x)
  else:
    par[y] = x
    find(y)

if m > 0:  
  for i in range(m):
    a, b = map(int, input().split())
    unite(a - 1, b - 1)
  
  ans = [0] * n
  Max = 0
  for i in range(n):
    find(i)
  for i in par:
    ans[i] += 1
  for i in ans:
    if i > Max:
      Max = i
  
  print(Max)
else:
  print(1)