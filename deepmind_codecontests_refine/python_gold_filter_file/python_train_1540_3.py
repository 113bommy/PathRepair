N, M = map(int, input().split())
A = map(int, input().split())
print(max(-1, N - sum(A)))
