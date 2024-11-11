n, m = map(int, input().split())
arr = list(map(int, input().split()))

print(max(-1, n - sum(arr)))
