# ダイクストラ
def main():
    import sys
    sys.setrecursionlimit(10**9)
    input = sys.stdin.readline
    from heapq import heappush, heappop

    N, M, S = map(int, input().split())
    S = min(S, 2500)
    graph = [[] for _ in range(N)]

    for u, v, a, b in (map(int, input().split()) for _ in range(M)):
        graph[u-1].append((v-1, a, b))
        graph[v-1].append((u-1, a, b))

    for i, (c, d) in enumerate(map(int, input().split()) for _ in range(N)):
        graph[i].append((i, -c, d))

    hq = [(0, 0, S)]
    INF = 10**18
    # dp[v][silver]
    # 都市vにsilverを使って到達したときの時間の最小値
    dp = [[INF]*2501 for _ in range(N)]
    dp[0][S] = 0

    while hq:
        time, v, silver = heappop(hq)
        if dp[v][silver] < time:
            continue

        for dest, a, b in graph[v]:
            next_s = silver-a if silver-a < 2500 else 2500
            if next_s < 0 or dp[dest][next_s] <= time+b:
                continue
            for i in range(next_s, -1, -1):
                if dp[dest][i] > time+b:
                    dp[dest][i] = time+b
                else:
                    break
            heappush(hq, (time+b, dest, next_s))

    print(*(min(dp[i]) for i in range(1, N)), sep='\n')

main()

