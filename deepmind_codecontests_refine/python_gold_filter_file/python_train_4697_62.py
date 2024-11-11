a, b, c = map(int, input().split())
x = max(a, b, c)
print(max(0, 2 * x - a - b - c + 1))