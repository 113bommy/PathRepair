# cook your dish here
#code
import math
import collections
from sys import stdin,stdout,setrecursionlimit
from bisect import bisect_left as bsl
from bisect import bisect_right as bsr
import heapq as hq
setrecursionlimit(2**20)

t = 1
t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    
    a = list(map(int, stdin.readline().rstrip().split()))

    e,o = [], []
    cnte, cnto = 0, 0
    for i in range(len(a)):
        if(a[i]%2==0):
            e.append(i+1)
            cnte+=1
        else:
            o.append(i+1)
            cnto+=1
            
    if(cnte%2==0):
        if(cnto!=0):
            for i in range(0,cnte,2):
                print(str(e[i]) + ' ' + str(e[i+1]))
            for i in range(0,cnto-2,2):
                print(str(o[i]) + ' ' + str(o[i+1]))
        else:
            for i in range(0,cnte-2,2):
                print(str(e[i]) + ' ' + str(e[i+1]))
            for i in range(0,cnto,2):
                print(str(o[i]) + ' ' + str(o[i+1]))
    else:
        cnte-=1
        cnto-=1
        for i in range(0,cnte,2):
            print(str(e[i]) + ' ' + str(e[i+1]))
        for i in range(0,cnto,2):
            print(str(o[i]) + ' ' + str(o[i+1]))