a, b, c = map(int, input().split())
print('Yes' if min(a, b) <= c <= max(a, b) else 'No')