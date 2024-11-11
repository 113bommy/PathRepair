import sys
input = sys.stdin.readline
LOCAL = len(sys.argv) > 1 and sys.argv[1] == 'LOCAL'


def dprint(*args):
  if LOCAL:
    print(*args)


n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]


import math
import itertools


def distanse(x1, y1, x2, y2):
  return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)


def isValid(ox, oy, r):
  # global ox, oy, r
  global xy
  for x, y in xy:
    if distanse(x, y, ox, oy) - r > 1e-6:
      return False
  return True


rs = []
for (x1, y1), (x2, y2) in itertools.combinations(xy, r=2):
  dprint(x1, y1, x2, y2)
  r = distanse(x1, y1, x2, y2) / 2
  ox = (x1 + x2) / 2
  oy = (y1 + y2) / 2
  dprint(ox, oy, r)
  if isValid(ox, oy, r):
    rs.append(r)
# for c1, c2 in itertools.combinations(xy, r=2):
#   dprint(c1, c2)
#   r = distanse(c1, c2)
#   o=(c1+c2)/2

for (x1, y1), (x2, y2), (x3, y3) in itertools.combinations(xy, r=3):
  # http://www.ambrsoft.com/TrigoCalc/Circle3D.htm
  a = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - x3 * y2
  b = (x1**2 + y1**2) * (y3 - y2) + (x2**2 + y2**2) * \
      (y1 - y3) + (x3**2 + y3**2) * (y2 - y1)
  c = (x1**2 + y1**2) * (x2 - x3) + (x2**2 + y2**2) * \
      (x3 - x1) + (x3**2 + y3**2) * (x1 - x2)
  d = (x1 ** 2 + y1 ** 2) * (x3 * y2 - x2 * y3) + (x2 ** 2 + y2 ** 2) * \
      (x1 * y3 - x3 * y1) + (x3 ** 2 + y3 ** 2) * (x2 * y1 - x1 * y2)
  if a == 0:
    continue
  ox = -b / (2 * a)
  oy = -c / (2 * a)
  r = math.sqrt((b ** 2 + c ** 2 - 4 * a * d) / (4 * a ** 2))
  if isValid(ox, oy, r):
    rs.append(r)

dprint(rs)
print('{:.18f}'.format(min(rs)))
