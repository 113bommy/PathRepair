n,q=map(int,input().split())
s = input()
td = [input().split() for _ in range(q)]
def f(x):
  for t,d in td:
    if s[x] == t:
      if d == "L":
        x -= 1
      else:
        x += 1
      if 0 <= x < n:
        continue
      return x < 0
def g(x):
  for t,d in td:
    if s[x] == t:
      if d == "L":
        x -= 1
      else:
        x += 1
      if 0 <= x < n:
        continue
      return x >= n
ok = -1
ng = n
while ng - ok > 1:
  mid = (ok + ng)//2
  if f(mid):
    ok = mid
  else:
    ng = mid
ans = ok + 1
ok = n
ng = -1
while ok - ng > 1:
  mid = (ok + ng) //2
  if g(mid):
    ok = mid
  else:
    ng = mid
print(n - (ans + (n - ok)))
