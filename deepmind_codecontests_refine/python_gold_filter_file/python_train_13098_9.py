from heapq import heappush, heappop
INF = float("inf")


def Dijkstra(n, s, g, mode):  # (頂点数，始点，グラフ，モード)を引数に
    dist = [INF] * n  # distを初期化
    dist[s] = 0  # 始点の距離は0
    hq = [(0, s)]  # (距離，頂点)で管理
    while hq:  # BFSと同様に探索
        d, v = heappop(hq)  # 最小距離とその頂点を取得
        if dist[v] < d:  # すでに最小になっている時はcontinue
            continue
        for w, *a in g[v]:  # そうでない時は隣接点への重みとその頂点を順に取得
            nd = d + a[mode]
            if dist[w] > nd:  # 最小になっていな開ければ更新してhqにpush
                dist[w] = nd
                heappush(hq, (nd, w))
    return dist


def main():
    n, m, s, t = map(int, input().split())
    s -= 1
    t -= 1
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, a, b = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append((v, a, b))
        g[v].append((u, a, b))

    d_yen = Dijkstra(n, s, g, 0)
    d_sunnk = Dijkstra(n, t, g, 1)

    ans = [0] * n
    cost = float("inf")
    for i in range(n-1, -1, -1):
        cost = min(cost, d_yen[i] + d_sunnk[i])
        ans[i] = 10 ** 15 - cost
    print(*ans, sep='\n')


if __name__ == "__main__":
    main()
