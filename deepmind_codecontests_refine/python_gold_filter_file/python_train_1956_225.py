N,K = map(int, input().split())
print(min(N, N%K, abs(N%K-K)))