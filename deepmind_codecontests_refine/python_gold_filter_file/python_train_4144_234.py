from math import ceil
A,B=map(int,input().split())
print(ceil((B-A)/(A-1))+1)