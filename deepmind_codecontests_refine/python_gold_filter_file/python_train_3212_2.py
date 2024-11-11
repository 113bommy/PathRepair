import sys

n, m, q = map(int, input().split())
dp1 = [[0] * (m + 1) for _ in range(n + 1)]
dpv = [[0] * (m + 1) for _ in range(n + 1)]
dph = [[0] * (m + 1) for _ in range(n + 1)]

prev_s = '0' * m

for i in range(n):
    s = input()
    for j in range(m):
        is1 = s[j] == '1'
        additional = 0

        if is1:
            dp1[i + 1][j + 1] = 1

            if i > 0 and prev_s[j] == '1':
                dpv[i + 1][j + 1] = 1
            if j > 0 and s[j - 1] == '1':
                dph[i + 1][j + 1] = 1
    prev_s = s

for i in range(1, n + 1):
    for j in range(1, m + 1):
        dp1[i][j] += dp1[i][j - 1]
        dpv[i][j] += dpv[i][j - 1]
        dph[i][j] += dph[i][j - 1]

for j in range(1, m + 1):
    for i in range(1, n + 1):
        dp1[i][j] += dp1[i - 1][j]
        dpv[i][j] += dpv[i - 1][j]
        dph[i][j] += dph[i - 1][j]

mp = map(int, sys.stdin.read().split())
buf = []
for x1, y1, x2, y2 in zip(mp, mp, mp, mp):
    cnt1 = dp1[x2][y2] - dp1[x1 - 1][y2] - dp1[x2][y1 - 1] + dp1[x1 - 1][y1 - 1]
    ver1 = dpv[x2][y2] - dpv[x1][y2] - dpv[x2][y1 - 1] + dpv[x1][y1 - 1]
    hor1 = dph[x2][y2] - dph[x1 - 1][y2] - dph[x2][y1] + dph[x1 - 1][y1]

    buf.append(cnt1 - ver1 - hor1)

print('\n'.join(map(str, buf)))
