n, s = map(int, input().split())
a, c = [0] * 1010, s
for _ in range(n):
    y, x = map(int, input().split())
    c    = max(c, y + x)
print(c)
