import sys

for _ in range(int(sys.stdin.readline().rstrip())):
    n, m = list(map(int, sys.stdin.readline().rstrip().split()))
    mp = []
    for _ in range(n):
        ln = list(map(int, sys.stdin.readline().rstrip().split()))
        mp.append(ln)
    pv = int((n + m - 1)/2)
    re = 0
    for i in range(pv):
        one = 0
        zero = 0
        for j in range(i + 1):
            x = j
            y = i - j
            if n - x - 1 < 0 or m - y - 1 < 0:
                continue
            if mp[x][y] == 0:
                zero += 1
            if mp[x][y] == 1:
                one += 1
            if mp[n - x - 1][m - y - 1] == 0:
                zero += 1
            if mp[n - x - 1][m - y - 1] == 1:
                one += 1
        re += min(one, zero)
    print(re)

