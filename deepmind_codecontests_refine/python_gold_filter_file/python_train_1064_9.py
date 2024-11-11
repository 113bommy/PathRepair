def solve(graph):
    ans = [-1 for i in range(len(graph) - 1)]
    for v in graph:
        if len(graph[v]) > 2:
            for i, (u, k) in enumerate(graph[v][:3]):
                ans[k] = i
            k = 0
            for i in range(3, len(ans)):
                while ans[k] != -1:
                    k += 1
                ans[k] = i
            return ans
    return list(range(len(graph) - 1))


def test():
    g1 = {1: [(2, 0), (3, 1)], 2: [(1, 0)], 3: [(1, 1)]}
    s1 = solve(g1)
    print(s1)
    assert s1 == [0, 1]
    g2 = {1: [(2, 0), (3, 1)], 2: [(1, 0), (4, 2), (5, 3)], 3: [(1, 1)], 4: [(2, 2)], 5: [(2, 3), (6, 5)], 6: [(5, 5)]}
    s2 = solve(g2)
    print(s2)
    assert s2 == [0, 3, 1, 2, 4]

if __name__ == '__main__':
    # test()
    n = int(input())
    graph = {i : [] for i in range(1, n + 1)}
    edges = []
    for i in range(n - 1):
        u, v = [int(c) for c in input().split()]
        graph[u].append((v, i))
        graph[v].append((u, i))
    ans = solve(graph)
    print(*ans, sep='\n')
