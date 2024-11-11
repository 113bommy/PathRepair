x,a,b = map(int, input().split())
print('A' if abs(b-x) > abs(a-x) else 'B')