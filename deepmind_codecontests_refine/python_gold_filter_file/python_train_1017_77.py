N, K, S = map(int, input().split())
if S < 10 ** 9:
    print(*([S] * K + [S + 1] * (N - K)))
else:
    print(*([S] * K + [1] * (N - K)))
