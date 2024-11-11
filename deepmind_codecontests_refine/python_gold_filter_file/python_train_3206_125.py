a, b, k = map(int, input().split())
print(max(a-k, 0), min(max(0, b+a-k), b))