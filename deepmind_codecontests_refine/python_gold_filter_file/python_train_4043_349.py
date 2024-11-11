a,b,x = map(int, input().split())
print('YNEOS'[a>x or b<x-a::2])