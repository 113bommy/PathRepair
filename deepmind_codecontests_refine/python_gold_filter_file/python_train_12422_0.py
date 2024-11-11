
from collections import Counter,defaultdict,deque
#from heapq import *
#from itertools import *
#from operator import itemgetter
#from itertools import count, islice
#from functools import reduce
#alph = 'abcdefghijklmnopqrstuvwxyz'
#dirs = [[1,0],[0,1],[-1,0],[0,-1]]
#from math import factorial as fact
#a,b = [int(x) for x in input().split()]
#sarr = [x for x in input().strip().split()]
import math
#from math import *
from heapq import *
import sys
input=sys.stdin.readline
#sys.setrecursionlimit(2**30)
#MOD = 10**9+7
def solve():
    n = int(input())
    b = sorted([int(x) for x in input().split()])
    s = 0
    a = [0]*n
    for i in range(1,n):
        d = b[i]-b[i-1]
        a[i] = d*i+a[i-1]
    #print(a)
    print(-sum(a)+max(b))
tt = int(input())
for test in range(tt):
    solve()
















#
