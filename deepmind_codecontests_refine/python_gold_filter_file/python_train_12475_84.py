n, a, b = map(int, input().split())
print('Alice' if (abs(a-b)-1)%2 == 1 else 'Borys')
