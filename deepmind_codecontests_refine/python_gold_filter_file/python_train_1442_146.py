r,g,b = map(int,input().split())
print('YNEOS'[(g*10+b)%4!=0::2])