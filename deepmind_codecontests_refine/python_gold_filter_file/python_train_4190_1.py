import sys
from array import array  # noqa: F401
from typing import List, Tuple, TypeVar, Generic, Sequence, Union  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]
    for u, v in (map(int, input().split()) for _ in range(n - 1)):
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    time = 0
    tin, tout, depth, par = [-1] * n, [-1] * n, [0] * n, [0] * n
    ei = [0] * n
    stack = [0]

    while stack:
        v = stack.pop()
        time += 1
        if tin[v] == -1:
            tin[v] = time

        for i, dest in enumerate(adj[v][ei[v]:], start=ei[v]):
            if par[v] == dest:
                continue
            par[dest] = v
            depth[dest] = depth[v] + 1
            ei[v] = i + 1
            stack.append(v)
            stack.append(dest)
            break
        else:
            tout[v] = time

    ans = ['NO'] * m
    for i, (_, *vertices) in enumerate(tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(m)):
        v = max(vertices, key=lambda x: depth[x])
        if all(tin[par[u]] <= tin[v] <= tout[par[u]] for u in vertices):
            ans[i] = 'YES'

    sys.stdout.buffer.write('\n'.join(ans).encode('utf-8'))


if __name__ == '__main__':
    main()
