from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
# from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())
#sys.setrecursionlimit(1000000)
mod = int(1e9 + 7)

for t in range(int(data())):
    n,s=input().split()
    n=int(n)
    l1=[0]*n
    l2=[0]*n
    cnt=n
    for i in range(n-2,-1,-1):
        if s[i]=='<':
            l1[i+1]=cnt
            cnt-=1
    for i in range(n-2,-1,-1):
        if s[i]=='>':
            if i==0:
                l1[0]=cnt
                cnt-=1
                j = i + 1
                while j < n and s[j - 1] == '>':
                    l1[j] = cnt
                    cnt -= 1
                    j += 1
            elif s[i-1]=='<':
                j=i+1
                while j<n and s[j-1]=='>':
                    l1[j]=cnt
                    cnt-=1
                    j+=1
    if l1[0]==0:
        l1[0]=1

    cnt = n
    for i in range(n-1):
        if s[i] == '>':
            l2[i] = cnt
            cnt -= 1
    for i in range(n-1):
        if s[i] == '<':
            if i == n-2:
                l2[n-1]=cnt
                cnt-=1
                j = i
                while j >=0 and s[j] == '<':
                    l2[j] = cnt
                    cnt -= 1
                    j -= 1
            elif s[i + 1] == '>':
                j = i
                while j >= 0 and s[j] == '<':
                    l2[j] = cnt
                    cnt -= 1
                    j -= 1
    if l2[n-1] == 0:
        l2[n-1] = 1

    print(*l2)
    print(*l1)