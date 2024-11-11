import io
import os

from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from heapq import heappush, heappop, heapify
from math import gcd, inf

from types import GeneratorType

# From https://github.com/cheran-senthil/PyRival/blob/master/pyrival/misc/bootstrap.py
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


def solve(N, LR, edges):

    graph = [[] for i in range(N)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    dp = [-1] * (2 * N)

    @bootstrap
    def dfs(u, p, i):
        if dp[2 * u + i] == -1:
            # i is 0 or 1
            a = LR[u][i]
            best = 0.0
            for v in graph[u]:
                if v != p:
                    yield dfs(v, u, 0)
                    yield dfs(v, u, 1)
                    best += max(
                        abs(a - LR[v][0]) + dp[2 * v + 0],
                        abs(a - LR[v][1]) + dp[2 * v + 1],
                    )
            dp[2 * u + i] = best
        yield

    root = 0
    dfs(root, -1, 0)
    dfs(root, -1, 1)
    return int(max(dp[2 * root + 0], dp[2 * root + 1]))


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    TC = int(input())
    for tc in range(1, TC + 1):
        (N,) = [int(x) for x in input().split()]

        LR = [[int(x) for x in input().split()] for i in range(N)]
        edges = [
            [int(x) - 1 for x in input().split()] for i in range(N - 1)
        ]  # 0 indexed
        ans = solve(N, LR, edges)
        print(ans)
