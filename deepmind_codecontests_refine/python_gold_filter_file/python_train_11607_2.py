x, y, a, b = map(int, input().split())
print('Vasiliy' if a < x and b < x + y or b < y and a < x + y else 'Polycarp')