n, a, b = [int(i) for i in input().split(' ')]
print('Alice' if abs(a-b) % 2 == 0 else 'Borys')