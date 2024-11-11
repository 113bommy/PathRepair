N, K = list(map(int, input().split()))
print(N + K) if K % N == 0 else print(K - N) 