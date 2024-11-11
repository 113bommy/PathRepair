import sys
import threading
from sys import stdin, stdout

sys.setrecursionlimit(10**9)
threading.stack_size(16*2048*2048)


def maximum_distributed_tree(n, uv_dic, p_a, edg):
    MOD = 10**9 + 7
    dfs(n, uv_dic, 1, -1, edg)
    edg.sort(reverse=True)
    p_a.sort(reverse=True)

    res = 0
    if len(p_a) - n + 1 > 0:
        for i in range(1, len(p_a) - n + 2):
            p_a[i] *= p_a[i-1]
            p_a[i] %= MOD
        del p_a[:(len(p_a) - n + 1)]

    for i in range(len(p_a)):
        res += edg[i]*p_a[i]
        res %= MOD

    for i in range(len(p_a), n-1):
        res += edg[i]
        res %= MOD

    return res


def dfs(n, uv_dic, node, parent, edg):

    cnt = 1
    nxt_a = uv_dic[node]
    for nxt in nxt_a:
        if nxt[1] != parent:
            nxtCnt = dfs(n, uv_dic, nxt[1], node, edg)
            edg[nxt[0]] = nxtCnt * (n - nxtCnt)
            cnt += nxtCnt

    return cnt


def solve():
    try:
        t = int(stdin.readline())
        for _ in range(t):
            n = int(stdin.readline())
            uv_dic = {}
            edg = [0 for _ in range(n-1)]
            for i in range(n-1):
                u, v = map(int, stdin.readline().split())
                if u not in uv_dic:
                    uv_dic[u] = []
                if v not in uv_dic:
                    uv_dic[v] = []
                uv_dic[u].append([i, v])
                uv_dic[v].append([i, u])

            m = int(stdin.readline())
            p_a = list(map(int, stdin.readline().split()))

            ans = maximum_distributed_tree(n, uv_dic, p_a, edg)
            stdout.write(str(ans) + '\n')
    except Exception as e:
        print("".join(str(e).split()))

threading.Thread(target=solve).start()
