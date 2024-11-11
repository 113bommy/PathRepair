N, M = map(int, input().split())
E = [set() for i in range(N)]
for i in range(M):
  s, t = map(int, input().split())
  s, t = s-1, t-1
  E[s].add(t)
Vs = [1000000.0]*N
Vs[-1] = 0
for i in reversed(range(N-1)):
  js = E[i]
  v = 0
  for j in js:
    v += Vs[j]
  v = 1+v/len(js)
  Vs[i] = v
r = Vs[0]
rs = [r]
Vs0 = Vs
for n in range(N-1):
  Vs = [1000000.0]*N
  for i in range(n+1, N):
    Vs[i] = Vs0[i]
  for i in reversed(range(n+1)):
    js = E[i]
    if i == n:
      jmin = max(js, key=lambda j: Vs[j])
      js = js-{jmin}
    if len(js) == 0:
      break
    #p = 1/len(js)
    v = 0
    for j in js:
      v += Vs[j]
    v = 1+v/len(js)
    Vs[i] = v
  r = Vs[0]
  rs.append(r)
#print(rs)
r = min(rs)
print(r)
