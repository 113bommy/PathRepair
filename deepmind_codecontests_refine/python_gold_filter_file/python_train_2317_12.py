import sys
import math
import collections
import heapq
import queue
import itertools
import functools
import operator
import time

readline = sys.stdin.readline
 
IPS = lambda: readline().rstrip()
IP = lambda: int(readline().rstrip())
MP = lambda: map(int, readline().split())
LS = lambda: list(map(int, readline().split()))

def solve():
    for _ in range(IP()):
        n = IP()
        arr = LS()
        odd,ev = 0,0
        oddar, evar = [], []
        for i in range(2*n):
            if arr[i]&1: 
                odd+=1
                oddar.append(i)
            else: 
                ev+=1
                evar.append(i)
                
        if odd&1:
            oddar.pop(); evar.pop();
        else:
            if odd>=2: oddar.pop(); oddar.pop()
            else:evar.pop(); evar.pop()

        i = 0
        while i<len(oddar):
            print(oddar[i]+1,oddar[i+1]+1)
            i+=2
            
        i = 0
        while i<len(evar):
            print(evar[i]+1,evar[i+1]+1)
            i+=2
       
if __name__ == "__main__":
    solve()