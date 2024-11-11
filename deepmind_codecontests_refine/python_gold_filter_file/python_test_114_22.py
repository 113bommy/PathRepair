from math import *
t = int(input())


for i in range(t):
    n = int(input())
    lis = list(map(int, input().split()))
    lis.sort()
    for i in range(1,n//2+1):
        print(lis[i],lis[0])
