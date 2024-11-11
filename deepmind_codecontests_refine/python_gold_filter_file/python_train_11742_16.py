from collections import defaultdict


def get_path(from_node, to_node, adj, nodes2edge):
    # from_nodeからto_nodeまでの最短パスで通るedgeを返す

    def dfs(node, parent, edges):
        if node == to_node:
            return edges
        min_path = None
        for child in adj[node]:
            if child == parent:
                continue
            path = dfs(child, node, edges + [nodes2edge[(node, child)]])
            if path is None:
                continue
            if min_path is None or len(min_path) > len(path):
                min_path = path
        return min_path

    return dfs(from_node, None, list())


def count_bits(n):
    return len([i for i in range(len('{:b}'.format(n))) if (n >> i) & 1 == 1])


def main():
    N = int(input())
    adj = defaultdict(list)
    nodes2edge = defaultdict(lambda :-1)
    for i in range(N - 1):
        a, b = list(map(lambda x: int(x) - 1, input().split(' ')))
        adj[a].append(b)
        adj[b].append(a)
        nodes2edge[(a, b)] = i
        nodes2edge[(b, a)] = i
    M = int(input())
    constraints = [list(map(lambda x: int(x) - 1, input().split(' '))) for _ in range(M)]
    # 各制約を「パス u->v 上の辺はすべて白」として扱い、包除原理で計算
    base = [0] * M  # 各制約で出てくる最短 u->v パス で通るedgeの2進表記
    for m, constraint in enumerate(constraints):
        u, v = constraint
        path = get_path(u, v, adj, nodes2edge)
        v = sum([2**e for e in path])
        base[m] = v
    dp = [0] * (2**M)  # 制約の集合で出てくる最短 u->v パスで通るedgeの和集合の2進表記
    ans = 2**(N - 1)
    for S in range(1, 2**M):
        lenbit_s = len('{:b}'.format(S))
        dp[S] = dp[S - (1 << (lenbit_s - 1))] | base[lenbit_s - 1]
        cnt_s = count_bits(S)
        cnt_dp = count_bits(dp[S])
        ans += (-1)**(cnt_s % 2) * 2**(N - 1 - cnt_dp)
    print(ans)


if __name__ == '__main__':
    main()
