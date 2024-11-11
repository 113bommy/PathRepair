x, a, b = map(int, input().split())
print('delicious' if (b-a) <= 0 else 'safe' if (b-a) <= x else 'dangerous')
