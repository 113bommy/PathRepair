from sys import stdin, gettrace, setrecursionlimit
from collections import deque

def readTree(n):
    adj = [set() for _ in range(n)]
    for _ in range(n-1):
        u,v = map(int, input().split())
        adj[u-1].add(v-1)
        adj[v-1].add(u-1)
    return adj

def treeOrderByDepth(n, adj):
    parent = [-2] + [-1]*(n-1)
    ordered = []
    q = deque()
    q.append(0)
    while q:
        c =q.popleft()
        ordered.append(c)
        for a in adj[c]:
            if parent[a] == -1:
                parent[a] = c
                q.append(a)
    return (ordered, parent)


if not gettrace():
    def input():
        return next(stdin)[:-1]


# def input():
#    return stdin.buffer.readline()

def main():
    n = int(input())
    aa = [int(a) for a in input().split()]
    adj = readTree(n)

    ordered, parent = treeOrderByDepth(n, adj)
    res = [2*a - 1 for a in aa]
    for nd in ordered[:0:-1]:
        if res[nd] > 0:
            res[parent[nd]] += res[nd]

    for nd in ordered[1:]:
        if res[nd] >= 0:
            res[nd] = max(res[nd], res[parent[nd]])
        else:
            res[nd] = max(-1, res[parent[nd]]- 1)

    print(' '.join(map(str, res)))


if __name__ == "__main__":
    main()