n, m = map(int, input().split())
e = [[int(x) for x in input().split()] for _ in range(m)]

u = [-1]*(n+1)

def find(x):
  return x if u[x] < 0 else find(u[x])

t = n*(n-1)// 2
s = [t]

for i in range(m-1,0,-1):
  a = find(e[i][0])
  b = find(e[i][1])
  if a > b:
    a, b = b, a
  if a != b:
    t -= u[a]*u[b]
    u[a] += u[b]
    u[b] = a
  s.append(t)

for i in reversed(s):
  print(i)
