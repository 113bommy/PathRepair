N, X = map(int, input().split())
m = [int(input()) for _ in range(N)]

X -= sum(m)
print(N + X // min(m))