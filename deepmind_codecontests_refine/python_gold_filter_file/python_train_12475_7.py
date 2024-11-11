n,a,b=map(int,input().split())
print('Borys' if abs(b - a) % 2  == 1 else 'Alice')