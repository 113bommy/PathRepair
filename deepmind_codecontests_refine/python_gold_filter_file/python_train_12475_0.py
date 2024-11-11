n, a, b = map(int, input().split())
print('Alice' if (a - b - 1) % 2 == 1 else 'Borys')