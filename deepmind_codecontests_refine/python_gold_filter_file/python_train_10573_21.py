a, b, c, d = map(int, input().split())
n = min(a, c, d)
m = min(b, max(a - n, 0))
print(n * 256 + m * 32)
