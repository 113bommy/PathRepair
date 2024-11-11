from functools import lru_cache

n, k = map(int, input().split())
h = [0] + list(map(int, input().split())) + [0]
INF = 10 ** 18


@lru_cache(maxsize=None)
def solve(i, nokori):
    if i == 0:
       return 0
    res = INF
    for j in range(nokori + 1):
        if i - 1 - j < 0:
            break
        diff = max(h[i] - h[i - 1 - j], 0)
        res = min(solve(i - 1 - j, nokori - j) + diff, res)
    return res


print(solve(n + 1, k))