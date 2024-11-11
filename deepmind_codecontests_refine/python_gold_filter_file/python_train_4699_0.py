from collections import deque

n, m, p = [int(v) for v in input().split()]
s = [int(v) for v in input().split()]

d = {'.': 0, '#': 10}
d.update({str(v) : v for v in range(1, p + 1)})

field = [[d[c] for c in input().strip()] for _ in range(n)]

ans = [0] * p
dists = [[[9999999 for _ in range(m)] for _ in range(n)] for _ in range(p)]
frontiers = [deque() for _ in range(p)]
for i in range(n):
    for j in range(m):
        pp = field[i][j]
        if 1 <= pp <= 9:
            frontiers[pp - 1].append((i, j, 0))
            ans[pp - 1] += 1
            dists[pp - 1][i][j] = 0

off = [(1, 0), (0, 1), (-1, 0), (0, -1)]
curr_lim = s[:]

def dump():
    for line in field:
        print(line)
    print()

while True:
    was = False
    for pp in range(1, p + 1):
        # dump()
        while frontiers[pp - 1]:
            i, j, dist = frontiers[pp - 1].popleft()
            if field[i][j] not in (0, pp):
                continue
            if dist > curr_lim[pp - 1]:
                frontiers[pp - 1].appendleft((i, j, dist))
                break
            if field[i][j] != pp:
                field[i][j] = pp
                ans[pp - 1] += 1
                was = True
            for di, dj in off:
                ni, nj = i + di, j + dj
                if 0 <= ni < n and 0 <= nj < m and field[ni][nj] == 0:
                    # print(ni, nj)
                    new_dist = dist + 1
                    if new_dist < dists[pp - 1][ni][nj]:
                        frontiers[pp - 1].append((ni, nj, new_dist))
                        dists[pp - 1][ni][nj] = new_dist
    if was:
        for i in range(p):
            curr_lim[i] += s[i]
    else:
        break

print(' '.join(str(v) for v in ans))
