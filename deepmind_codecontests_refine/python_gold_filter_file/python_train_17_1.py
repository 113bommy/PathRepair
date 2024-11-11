from math import *
import os, sys
from io import BytesIO
 
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n):
    b.append((-a[i], i))
b.sort()
#print(b)
for i in range(int(input())):
    k, pos = map(int, input().split())
    tmp = []
    for j in range(k):
        tmp.append(b[j][1])
    tmp.sort()
    #print(tmp)
    print(a[tmp[pos - 1]])
