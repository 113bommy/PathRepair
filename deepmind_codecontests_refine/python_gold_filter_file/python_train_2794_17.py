x,a,b = map(int,input().split())

print('B' if abs(a-x) > abs(b-x) else 'A')