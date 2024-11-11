N, K = map(int, input().split())

Map = [[[0]*K for i in range(K)] for j in range(2)]
for i in range(N):
  x, y, c = input().split()
  x, y = int(x), int(y)
  if c == 'B':
    c = 0
  else:
    c = 1
  nx, ny = x//K, y//K
  if (nx + ny) % 2:
    c = 1 - c
  x %= K
  y %= K
  Map[c][x][y] += 1

def get_v(c, x, y):
  global Map
  if x < 0 or y < 0:
    return 0
  else:
    return Map[c][x][y]

for c in range(2):
  for x in range(K):
    for y in range(K):
      Map[c][x][y] += get_v(c, x-1, y) + get_v(c, x, y-1) - get_v(c, x-1, y-1)

ans = 0
for x in range(K+1):
  for y in range(K+1):
    b2 = get_v(0, x-1, K-1) + get_v(0, K-1, y-1) - 2*get_v(0, x-1, y-1)
    w1 = get_v(1, x-1, K-1) + get_v(1, K-1, y-1) - 2*get_v(1, x-1, y-1)
    b1 = Map[0][K-1][K-1] - b2
    w2 = Map[1][K-1][K-1] - w1
    ans = max(ans, b1+w1, b2+w2)

print(ans)