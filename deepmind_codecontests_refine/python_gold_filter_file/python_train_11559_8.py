N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
    s, t = map(int, input().split())
    G[s].append(t)


def topological_sort(g):
    topological_list = []
    visited = set()

    def dfs(n):
        for e in g[n]:
            if e not in visited:
                dfs(e)
        topological_list.append(n)
        visited.add(n)

    for i in range(len(g)):
        if i not in visited:
            dfs(i)

    return topological_list[::-1]


print(*topological_sort(G), sep="\n")

