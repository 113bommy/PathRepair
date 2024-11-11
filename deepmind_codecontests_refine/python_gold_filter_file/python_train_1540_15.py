N, M = map(int, input().split())
As = list(map(int, input().split()))
print(max(-1, N - sum(As)))
