n, m = map(int, input().split())
ar = list(map(int, input().split()))

print(max(-1, n - sum(ar)))