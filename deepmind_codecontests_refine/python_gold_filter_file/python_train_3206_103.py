a, b, k = map(int, input().split())
print(max(a - k, 0), min(max(b + (a - k), 0), b))
