x, a, b = map(int, input().split())
print('B' if abs(x - a) > abs(x - b) else 'A')