def popcount(x):
  r, q = 0, x
  while x:
    r += 1
    x &= x - 1
  return r, q
 
n = int(input())
r = range(n)
a = [[0, 0] for _ in r]
for i in r:
  for _ in range(int(input())):
    x, y = map(int, input().split())
    a[i][y] |= 1 << (x - 1)
l = (1 << n) - 1 
b = sorted(map(popcount, range(1, l + 1)))
ans = next((i for i, x in reversed(b)
           if all(a[j][0] & x == a[j][1] & l - x == 0 for j in r if x >> j & 1)), 0)
print(ans)
