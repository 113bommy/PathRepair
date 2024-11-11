A, B, K = map(int, input().split())
print(max(A - K, 0), max(min(A + B - K, B), 0))
