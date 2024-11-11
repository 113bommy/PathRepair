x,a,b = map(int, input().split())
print('A' if abs(x-b) > abs(x-a) else 'B')