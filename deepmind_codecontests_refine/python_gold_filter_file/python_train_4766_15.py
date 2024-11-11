x, y = map(int, input().split())
print('Yes' if y%2 == 0 and x <= y/2 and  y / 4 <= x else 'No')
