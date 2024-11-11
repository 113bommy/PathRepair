x,a,b=map(int, input().split())
print('A' if abs(a-x)<abs(x-b) else 'B')