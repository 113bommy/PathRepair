import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

n, m = map(int, input().split())
if m%2:
  print(-1)
else:
  G = [[] for _ in range(n+1)]
  par = [-1]*(n+1)
  ch = [[] for _ in range(n+1)]
  seen = [False]*(n+1)
  used = set()
  C = [0]*(n+1)
  for _ in range(m):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)
  
  stack = [1]
  seen[1] = True
  while stack:
    v = stack.pop()
    for nv in G[v]:
      if seen[nv]:
        if par[v] != nv:
          if (min(v, nv), max(v, nv)) not in used:
            used.add((min(v, nv), max(v, nv)))
            print(v, nv)
            C[v] ^= 1
      else:
        seen[nv] = True
        par[nv] = v
        ch[v].append(nv)
        stack.append(nv)
  
  def bottom_up(v):
    for nv in ch[v]:
      bottom_up(nv)
    if v == 1:
      return
    if C[v]:
      C[v] ^= 1
      print(v, par[v])
    else:
      C[par[v]] ^= 1
      print(par[v], v)
      
  bottom_up(1)