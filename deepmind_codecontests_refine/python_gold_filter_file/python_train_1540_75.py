N, M, *A = map(int, open(0).read().split())
print(max(N - sum(A), -1))