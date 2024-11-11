N, X = map(int, input().split())
l = [int(input()) for _ in range(N)]

print(N + (X - sum(l)) // min(l))