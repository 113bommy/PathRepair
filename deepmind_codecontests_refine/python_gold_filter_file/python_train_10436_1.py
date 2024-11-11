from collections import deque
from collections import OrderedDict
import math

import sys
import os
from io import BytesIO
import threading
import bisect


import heapq



#sys.stdin = open("F:\PY\\test.txt", "r")
input = sys.stdin.readline


#file = open("F:\PY\\test.txt", "r")
#import file.readline as input

def run(val):
    array = []
    while(val>0):
        array.append(val%10)
        val=val//10
    minElv = 9999999999
    maxElv = 0
    for i in range(len(array)):
        minElv= min(array[i], minElv)
        maxElv = max(array[i], maxElv)
    
    return minElv*maxElv



for t in range(int(input())):
    n = int(input())
    iA = list(map(int, input().split()))
    if t==14342897657:
        #print(n)
        print(str(iA[0])+"_"+str(iA[1])+"_"+str(iA[2])+"_"+str(iA[3])+"_"+str(iA[4])+"_"+str(iA[5]))
        exit(0)
    #cV = [0]*300005
    cD = dict()
    for i in range(n):
        if iA[i] in cD:
            cD[iA[i]]+=1
        else:
            cD[iA[i]]=1
    answer = 0
    sL = 0
    sortDic = OrderedDict(sorted(cD.items()))
    for i in sortDic.keys():
        #print(i)
        j = sortDic[i]
        answer+=j//i
        sL+= j%i
        if sL//i>0:
            answer+=sL//i
            sL=sL%i
    print(answer)
    
    
    
    
    
    
    
    
    
    
        