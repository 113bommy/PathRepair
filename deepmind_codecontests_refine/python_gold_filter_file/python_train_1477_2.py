from heapq import heappush, heappop
from collections import deque,defaultdict,Counter
import itertools
from itertools import permutations
import sys
import bisect
sys.setrecursionlimit(10**6)
def SI():
    return input().split()
def MI():
    return map(int,input().split())
def I():
    return int(input())
def LI():
    return [int(i) for i in input().split()]
YN=['Yes','No']
YNeos='YNeos'
GYN=['Yes','trumpet']
mo=10**9+7
imp='IMPOSSIBLE'

t=I()
for _ in range(t):
    n=I()
    #n=10**9
    y=int((8*(10**4))**0.5)
    Y=y**2+y+1
    x=n//Y
    z=n%Y
    #print((x,y,z),Y,x+y+z+4,10**9//(8*(10**4)))
    
    ans='1'*x+'3'*y+'7'+'1'*z+'337'
    print(ans)

    