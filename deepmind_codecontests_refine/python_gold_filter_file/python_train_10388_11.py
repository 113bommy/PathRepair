import bisect
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = tuple(map(int, input().split()))
edge = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    x, y = map(int, input().split())
    edge[x].append(y)
    edge[y].append(x)

ans = [-1] * (N + 1)
inf = 10**18
LIS = [inf] * (N + 10)


def DFS(s, parent=0):
    a = A[s - 1]
    i = bisect.bisect_left(LIS, a)
    v = LIS[i]
    LIS[i] = a
    ans[s] = bisect.bisect_left(LIS, inf)
    for t in edge[s]:
        if t == parent:
            continue
        DFS(t, s)
    # 頂点sでの結果をもとに戻す
    LIS[i] = v
    return


DFS(1)
print(*ans[1:], sep="\n")