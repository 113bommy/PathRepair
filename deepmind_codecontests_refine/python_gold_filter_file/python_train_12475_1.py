n,a,b = map(int, input().split())
print('Alice' if abs(a-b) % 2 == 0 else 'Borys')