import sys
import math
import collections
import heapq
import decimal
input=sys.stdin.readline
n,k=(int(i) for i in input().split())
if(n*k>(n*(n-1))//2):
    print(-1)
else:
    print(n*k)
    for i in range(1,n+1):
        c=0
        if(i==n):
            j=1
        else:
            j=i+1
        while(c<k):
            print(i,j)
            if(j==n):
                j=1
            else:
                j+=1
            c+=1