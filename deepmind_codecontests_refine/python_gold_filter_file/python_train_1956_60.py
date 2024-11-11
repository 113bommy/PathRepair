N, K = map(int, input().split())
k = N%K
print(min(k, K-k))
