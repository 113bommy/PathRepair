from collections import Counter

def solve():
    MOD = 10**9 + 7

    N, K = map(int, input().split())
    Ass = [tuple(map(int, input().split())) for _ in range(N)]

    maxD = K.bit_length() - 1

    dp = [[Counter() for _ in range(N)] for _ in range(maxD+1)]
    for v, As in enumerate(Ass):
        v2s = []
        for v2, A in enumerate(As):
            if A == 1:
                v2s.append(v2)
        dp[0][v] = Counter(v2s)
    for d in range(1, maxD+1):
        for v in range(N):
            for v2, num2 in dp[d-1][v].items():
                for v3, num3 in dp[d-1][v2].items():
                    dp[d][v][v3] += num2 * num3
                    dp[d][v][v3] %= MOD

    anss = [1] * N
    for d in range(maxD+1):
        if K & (1<<d):
            ans2s = [0] * N
            for v in range(N):
                for v2, num in dp[d][v].items():
                    ans2s[v2] += anss[v] * num
                    ans2s[v2] %= MOD
            anss = ans2s

    print(sum(anss) % MOD)


solve()
