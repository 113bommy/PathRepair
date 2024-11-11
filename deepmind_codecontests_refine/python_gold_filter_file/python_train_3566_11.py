import math;
from math import log2,sqrt;
from bisect import bisect_left,bisect_right
import bisect;
import sys;
from sys import stdin,stdout
import os
sys.setrecursionlimit(pow(10,6))
import collections
from collections import defaultdict
from statistics import median
# input=stdin.readline
# print=stdout.write
inf = float("inf")
def fun():
    maxa=0;
    count=0;
    index=0
    while(index+1<len(l)):
        count=max(0,count-l[index]+l[index+1])
        maxa=max(maxa,count)

        index+=2
    index=2;
    count=0
    while(index<len(l)):
        count=max(0,count-l[index]+l[index-1])
        maxa=max(maxa,count)
        index+=2
    return maxa
for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    ans=fun()
    suma=sum(l[::2])

    print(suma+ans)
