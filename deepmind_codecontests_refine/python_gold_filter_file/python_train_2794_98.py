x, a, b = map(float, input().split())

print('A' if abs(x-a) < abs(x-b) else 'B')