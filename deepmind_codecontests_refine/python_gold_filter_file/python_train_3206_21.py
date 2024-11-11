
A, B, K = map(int, input().split())

print(max(0, A-K), max(B-(max(0, K-A)), 0))
