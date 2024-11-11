from math import ceil
n,w,perc=list(map(int,input().split()))
print(max(0,ceil(n*(perc/100))-w))