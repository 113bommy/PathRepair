from sys import stdin
from collections import deque
from itertools import chain
input = stdin.readline
def getint(): return int(input())
def getints(): return list(map(int, input().split()))
def getint1(): return list(map(lambda x : int(x) - 1, input().split()))
def getstr(): return input()[:-1]


def solve():
    n, x, y = getints()
    a = getints()
    # table = [[] for _ in range(n + 1)]
    ind = [[] for _ in range(n + 2)]
    for i, color in enumerate(a):
        ind[color].append(i)
    not_seen = 0
    for i in range(1, n + 2):
        if len(ind[i]) == 0:
            not_seen = i
            break
    max_cnt = max(len(g) for g in ind)
    # print(max_cnt)
    table = [[] for _ in range(max_cnt + 1)]
    for i, col in enumerate(ind[1:], 1):
        if len(col) > 0:
            table[len(col)].append(i)
    # for t in table:
    #     print(t)
    ans = [0] * n
    for _ in range(x):
        assert len(table[max_cnt]) > 0
        color = table[max_cnt].pop()
        assert len(ind[color]) > 0
        i = ind[color].pop()
        ans[i] = color
        if max_cnt > 1:
            table[max_cnt - 1].append(color)
        if len(table[max_cnt]) == 0: 
            max_cnt -= 1
    if 2 * max_cnt > 2 * n - x - y:
        print("NO")
        return
    rest = list(chain(*ind))
    to_change, offset, m = n - y, (n - x) >> 1, n - x
    for i in range(m):
        ans[rest[i]] = a[rest[(i + offset) % m]]
        if ans[rest[i]] == a[rest[i]]:
            ans[rest[i]] = not_seen
            to_change -= 1
    i = 0
    while to_change > 0:
        if ans[rest[i]] != not_seen:
            ans[rest[i]] = not_seen
            to_change -= 1
        i += 1
    print("YES")
    print(*ans)


if __name__ == "__main__":
    # solve()
    # for t in range(getint()):
    #     print('Case #', t + 1, ': ', sep='')
    #     solve()
    for _ in range(getint()):
        solve()
