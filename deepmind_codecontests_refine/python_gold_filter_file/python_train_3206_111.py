A, B, K = map(int, input().split())
print(max(A - K, 0), max(B - max(K - A, 0), 0))
