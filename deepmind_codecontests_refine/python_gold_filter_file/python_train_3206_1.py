A, B, K = map(int, input().split())
print(max(0, A - K), max(0, min(A + B -K, B)))