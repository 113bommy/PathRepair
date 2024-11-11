A, B, K = map(int, input().split())
A_ = min(A, K)
print(A-A_, max(0, B-(K-A_)))