N, K = map(int, input().split())
print(min(K-N%K, N % K))