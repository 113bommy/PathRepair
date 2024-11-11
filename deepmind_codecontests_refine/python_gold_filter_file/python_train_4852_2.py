n, a = map(int, input().split())
m = (a * n + 90) // 180
m = max(1, m)
print(2, 1, min(2 + m, n))
