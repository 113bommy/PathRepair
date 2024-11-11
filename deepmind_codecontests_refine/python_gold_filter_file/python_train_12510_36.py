import math as m
n,d=map(int,input().split())
print(int((2*n+3-m.sqrt(9+8*(n+d)))/2))