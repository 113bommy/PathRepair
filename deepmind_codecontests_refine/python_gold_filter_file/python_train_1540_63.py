n, m = map(int, input().split())
s = sum(map(int, input().split()))
print(n-s if s <= n else -1)