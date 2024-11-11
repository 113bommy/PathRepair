import sys

sys.setrecursionlimit(5005)
SENTINEL = 10 ** 13

n = int(input())
aaa = list(map(int, input().split()))
links = [set() for _ in [0] * n]
for line in sys.stdin.readlines():
    u, v = map(int, line.split())
    u -= 1
    v -= 1
    links[u].add(v)
    links[v].add(u)


def dfs(v, p):
    a = aaa[v]
    ret1 = [a]
    ret2 = [a]
    if a < 0:
        ret1[0] = SENTINEL

    for u in links[v]:
        if u == p:
            continue
        res1, res2 = dfs(u, v)
        new1 = [SENTINEL] * (len(ret1) + len(res1))
        new2 = [SENTINEL] * (len(ret2) + len(res2))
        for i, t in enumerate(ret1):
            for j, s in enumerate(res1):
                new1[i + j] = min(new1[i + j], t + s)
                if s < SENTINEL:
                    new1[i + j + 1] = min(new1[i + j + 1], t)
            for j, s in enumerate(res2):
                new2[i + j] = min(new2[i + j], t + s)
                if s < 0:
                    new1[i + j + 1] = min(new1[i + j + 1], t)
        for i, t in enumerate(ret2):
            for j, s in enumerate(res1):
                new2[i + j] = min(new2[i + j], t + s)
                if s < SENTINEL:
                    new2[i + j + 1] = min(new2[i + j + 1], t)
            for j, s in enumerate(res2):
                new2[i + j] = min(new2[i + j], t + s)
                if s < 0:
                    new2[i + j + 1] = min(new2[i + j + 1], t)

        # print(' ', '1', p, v, u, ret1, res1, new1)
        # print(' ', '2', p, v, u, ret2, res2, new2)
        ret1, ret2 = new1, new2

    return ret1, ret2


res1, res2 = dfs(0, -1)
ans1, ans2 = 0, 0
for ans1, s in enumerate(res1):
    if s < SENTINEL:
        break
for ans2, s in enumerate(res2):
    if s < 0:
        break
print(min(ans1, ans2))
