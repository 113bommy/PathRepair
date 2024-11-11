N, K = map(int, input().split())
M = [int(input()) for _ in range(N)]
print(N + (K - sum(M)) // min(M))