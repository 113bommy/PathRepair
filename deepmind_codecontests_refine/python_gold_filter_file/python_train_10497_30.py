n, k = map(int, input().split())
mp1 = [[0] * k for _ in range(k)]
mp2 = [[0] * k for _ in range(k)]
for _ in range(n):
  x, y, c = input().split()
  t = int(x) // k + int(y) // k
  x = int(x) % k
  y = int(y) % k
  if c == "B":
    t += 1
  if t % 2:
    mp1[y][x] += 1
  else:
    mp2[y][x] += 1

for x in range(1, k):
  mp1[0][x] += mp1[0][x - 1]
  mp2[0][x] += mp2[0][x - 1]

for y in range(1, k):
  acc1 = 0
  acc2 = 0
  for x in range(k):
    acc1 += mp1[y][x]
    mp1[y][x] = acc1 + mp1[y - 1][x]
    acc2 += mp2[y][x]
    mp2[y][x] = acc2 + mp2[y - 1][x]

ans = 0
sum1 = mp1[k - 1][k - 1]
sum2 = mp2[k - 1][k - 1]
mp1k = mp1[k - 1]
mp2k = mp2[k - 1]
for y in range(k):
  mp1y = mp1[y]
  mp1yk = mp1y[k - 1]
  mp2y = mp2[y]
  mp2yk = mp2y[k - 1]
  for x in range(k):
    mp1yx = mp1y[x]
    mp2yx = mp2y[x]
    mp1kx = mp1k[x]
    mp2kx = mp2k[x]

    ans = max(ans, 2 * mp1yx + sum1 - mp1yk - mp1kx + mp2kx + mp2yk - 2 * mp2yx)
    ans = max(ans, 2 * mp2yx + sum2 - mp2yk - mp2kx + mp1kx + mp1yk - 2 * mp1yx)

print(ans)