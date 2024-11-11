N, X = map(int, input().split())
M = [int(input()) for _ in range(N)]
X -= sum(M)
print(N + X // min(M))
