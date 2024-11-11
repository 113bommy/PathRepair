N, X = map(int, input().split())
d = [int(input()) for i in range(N)]

print(N + (X - sum(d)) // min(d))