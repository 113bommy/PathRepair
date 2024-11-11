def solve():
    N, M = map(int, input().split())
    edges = [[] for _ in [0]*N]
    r_edges = [[] for _ in [0]*N]

    for _ in [0]*M:
        a, b = map(int, input().split())
        edges[a].append(b)
        r_edges[b].append(a)

    c = kosaraju(edges, r_edges)
    group = [0]*N
    for i in range(len(c)):
        for v in c[i]:
            group[v] = i

    result = []
    append = result.append
    for _ in [0]*int(input()):
        a, b = map(int, input().split())
        append("1" if group[a] == group[b] else "0")

    print("\n".join(result))


def kosaraju(edges, reverse_edges):
    import sys
    sys.setrecursionlimit(10**7)
    v_count = len(edges)
    order = [0]*v_count
    k = [1]

    def get_order(v):
        order[v] = 1
        for dest in (_v for _v in edges[v] if order[_v] == 0):
            get_order(dest)
        order[v] = k[0]
        k[0] += 1

    def get_components(v):
        order[v] = 0
        return [v] + [_v for dest in reverse_edges[v] if order[dest] > 0 for _v in get_components(dest)]

    for v in (_v for _v in range(v_count) if order[_v] == 0):
        get_order(v)
    return [get_components(v) for v, _ in sorted(enumerate(order), key=lambda x: x[1], reverse=True) if order[v] > 0]

if __name__ == "__main__":
    solve()