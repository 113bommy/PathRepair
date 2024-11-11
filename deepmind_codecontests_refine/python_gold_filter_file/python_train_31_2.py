from math import ceil

n,x,y = map(int,input().split())

print( max(0,ceil((n/100)*y)-x) )

