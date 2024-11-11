def topological_sort(G, revG):
  n = len(revG)
  S = set()
  for u in revG:
    if len(revG[u]) == 0:
      S.add(u)
  L = []
  while len(S) > 0:
    u = S.pop()
    L.append(u)
    for v in G[u]:
      revG[v].remove(u)
      if len(revG[v]) == 0:
        S.add(v)
  return L


n, m = [int(i) for i in input().strip().split(' ')]
G = {}
revG = {}
for i in range(n):
  G[i] = set()
  revG[i] = set()
for _ in range(m):
  s, t = [int(i) for i in input().strip().split(' ')]
  G[s].add(t)
  revG[t].add(s)


L = topological_sort(G, revG)
for n in L:
  print(n)