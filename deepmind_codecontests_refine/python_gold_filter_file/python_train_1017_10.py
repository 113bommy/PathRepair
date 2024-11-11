N, K, S = [int(i) for i in input().split()]
ans = [S] * K
ans += [10**9 if S != 10**9 else 10**9 - 1] * (N - K)
print(*ans)

