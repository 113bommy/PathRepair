import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
if a[-1] > 1:
  print(-1)
  exit(0)
table = [-1] * N
s = []
for i in range(N - 1, -1, -1):
  if a[i] == 1: s.append(i)
  if a[i] == 2:
    if len(s) == 0:
      print(-1)
      exit(0)
    j = s.pop()
    table[j] = i

s = []
for i in range(N - 1, -1, -1):
  if a[i] == 3:
    if len(s) == 0:
      print(-1)
      exit(0)
    j = s.pop()
    table[j] = i
  if a[i] and (table[i] == -1): s.append(i)
s = []
for i in range(N):
  if table[i] >= 0: s.append((table[i] + 1, i + 1))
#print(s)
s.reverse()
res = []
z = 1
call = [0] * N
while len(s):
  x, y = s.pop()
  if call[x - 1]:
    if a[x - 1] >= 2: res.append((call[x - 1], y))
    if a[x - 1] == 3:
      res.append((z, y))
      call[y - 1] = z
      z += 1
  elif a[x - 1] == 2:
    res.append((z, x))
    res.append((z, y))
    z += 1
  elif a[x - 1] == 3:
    res.append((z, x))
    res.append((z, y))
    res.append((z + 1, y))
    call[y - 1] = z + 1
    z += 2
if len(res) and res[-1][0] == z: z += 1
#print(res)
for i in range(N):
  if a[i] == 1 and (table[i] == -1) and (call[i] == 0):
    res.append((z, i + 1))
    if z > N:
      print(-1)
      exit(0)
    z += 1
res = set(res)
print(len(res))
for r in sorted(res): print(*r)