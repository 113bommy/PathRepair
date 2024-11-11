N, K, S = map(int, input().split())

ans = [S] * K + [10 ** 9 if S != 10 ** 9 else 1] * (N - K)
print(*ans)
