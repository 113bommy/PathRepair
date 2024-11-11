import math
import sys
#from collections import deque, Counter, OrderedDict, defaultdict
#import heapq
#ceil,floor,log,sqrt,factorial,pow,pi,gcd
#import bisect
#from bisect import bisect_left,bisect_right
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().split()))
n=inp()
i=n//7
flag=1
a=7
b=4
while i*a>=0:
    if (n - (i * a)) % b == 0:
        flag=0
        c=n-a*i
        d=c//b
        print('4'*d+'7'*i)
        break
    i = i - 1

if flag:
    print(-1)