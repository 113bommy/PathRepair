import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
L = int(input())
k = 1
while a[-1] // (L * pow(2, k)): k += 1
e = [[0] * k for _ in range(N)]
for i in range(N):
  t = L + a[i]
  ok = i
  ng = N
  while ng - ok > 1:
    m = (ok + ng) // 2
    if a[m] <= t: ok = m
    else: ng = m
  e[i][0] = ok
for j in range(len(e[i]) - 1):
  for i in range(N):
    x = e[i][j]
    e[i][j + 1] = e[x][j]
#print(e)

def doubling(u, v):
  if u == v: return 0
  ok = -1
  ng = len(e[u])
  while ng - ok > 1:
    m = (ok + ng) // 2
    if e[u][m] < v: ok = m
    else: ng = m
  if ok < 0: return 1
  return doubling(e[u][ok], v) + pow(2, ok)

Q = int(input())
for _ in range(Q):
  x, y = map(int, input().split())
  x -= 1
  y -= 1
  if x > y: x, y = y, x
  print(doubling(x, y))
