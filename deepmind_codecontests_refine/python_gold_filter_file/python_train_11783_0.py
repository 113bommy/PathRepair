from sys import stdin
from sys import setrecursionlimit as SRL; SRL(10**7)
rd = stdin.readline
rrd = lambda: map(int, rd().strip().split())


n,k = rrd()

s = []
cal = [[0]*(n+10) for _i in range(n+10)]

for i in range(n):
    s.append(str(rd()))

ans = 0

for i in range(n):
    j = 0
    while j < n and s[i][j] == 'W':
        j += 1
    l = j

    if j >= n:
        ans += 1
        continue

    j = n-1
    while j >= 0 and s[i][j] == 'W':
        j -= 1
    r = j

    if r - l + 1 > k:
        continue

    l1 = max(0,i - k + 1)
    r1 = i + 1
    l2 = max(0,r - k + 1)
    r2 = l + 1

    cal[l1][l2] += 1
    cal[r1][l2] -= 1
    cal[l1][r2] -= 1
    cal[r1][r2] += 1


for i in range(n):
    j = 0
    while j < n and s[j][i] == 'W':
        j += 1
    l = j

    if j >= n:
        ans += 1
        continue

    j = n-1
    while j >= 0 and s[j][i] == 'W':
        j -= 1
    r = j

    if r-l+1 > k:
        continue

    l1 = max(0,i - k + 1)
    r1 = i + 1
    l2 = max(0,r - k + 1)
    r2 = l + 1

    cal[l2][l1] += 1
    cal[l2][r1] -= 1
    cal[r2][l1] -= 1
    cal[r2][r1] += 1

for i in range(n):
    for j in range(n):
        if j:
            cal[i][j] += cal[i][j-1]


pans = 0

for j in range(n):
    for i in range(n):
        if i:
            cal[i][j] += cal[i-1][j]
        pans = max(pans,cal[i][j])



print(ans+pans)


