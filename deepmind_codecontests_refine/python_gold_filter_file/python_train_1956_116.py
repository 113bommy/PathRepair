x, k = map(int, input().split())
print(min(x%k, k - x%k))