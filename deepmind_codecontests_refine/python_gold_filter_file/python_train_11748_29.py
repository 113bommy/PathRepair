x, a, b = map(int, input().split())
print('delicious' if a-b>=0 else 'safe' if a+x-b>=0 else 'dangerous')