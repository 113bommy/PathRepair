from collections import defaultdict
import sys


sys.setrecursionlimit(10 ** 6)


def ext_euc(a, b):
    if b == 0:
        return 1, 0, a
    y, x, v = ext_euc(b, a % b)
    y -= (a // b) * x
    return x, y, v


def mod_inv(a, mod):
    x, _, _ = ext_euc(a, mod)
    return x % mod


def main():
    MOD = 10 ** 9 + 7
    N = int(input())
    adj = defaultdict(list)
    for _ in range(N - 1):
        A, B = list(map(lambda x: int(x) - 1, input().split()))
        adj[A].append(B)
        adj[B].append(A)

    # 2 ** n の事前計算
    pow_2 = [1 for _ in range(N + 1)]
    for i in range(1, N + 1):
        pow_2[i] = pow_2[i - 1] * 2 % MOD

    # 分子：sum_{i} (node i が穴あき度の値としてカウント対象になるような塗り方)
    # node_num[(node, dir_node)]: nodeから見てdir_node方向に存在するノードの数
    #         5               6
    #        (6)             (6)
    #         |               |
    #        (1)             (1)
    # 0(6)-(1)1(4)-(3)2(3)-(4)3(1)-(6)4
    node_num = defaultdict(int)

    def dfs(node=0, parent=None):
        child_list = [n for n in adj[node] if n != parent]
        if len(child_list) == 0:
            node_num[(node, parent)] = N - 1
            node_num[(parent, node)] = 1
            return 1
        n_descendant = 1  # self
        for child in child_list:
            n_descendant += dfs(child, node)
        if parent is not None:
            node_num[(node, parent)] = N - n_descendant
            node_num[(parent, node)] = n_descendant
        return n_descendant

    dfs()

    numer = 0
    for node in range(N):
        if len(adj[node]) <= 1:
            # 端（次数1）のノードはカウント対象にならない
            continue
        cnt_not = 0  # node が穴あき度の値としてカウントされないケース
        for dir_node in adj[node]:
            # dir_node方向のノードは自由、それ以外の方向のノードは全部白
            cnt_not += pow_2[node_num[(node, dir_node)]]
        cnt_not -= len(adj[node]) - 1  # 「全部白塗り」の重複カウントを除去
        numer += pow_2[N - 1] - cnt_not  # node自身は白でないとカウントされないので、全体のパターン数が2 ** (N-1)

    # 分母：2 ** N （全部の塗り方）
    denom = pow_2[N]

    # 答え
    print(numer * mod_inv(denom, MOD) % MOD)


if __name__ == '__main__':
    main()