A, B, K = map(int, input().split())
print(max(0, A-K), max(A+B-K-max(0, A-K), 0))