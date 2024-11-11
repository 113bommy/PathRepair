N, M = map(int, input().split())
A = list(map(int, input().split()))
S = sum(A)
print(max(N-S, -1))