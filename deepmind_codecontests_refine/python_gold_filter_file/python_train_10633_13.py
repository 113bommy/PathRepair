from collections import deque, Counter, OrderedDict
from heapq import nsmallest, nlargest, heapify, heappop ,heappush, heapreplace
from math import ceil,floor,log,log2,sqrt,gcd,factorial,pow,pi
from bisect import bisect_left,bisect_right

def binNumber(n,size=4):
    return bin(n)[2:].zfill(size)

def iar():
    return list(map(int,input().split()))

def ini():
    return int(input())

def isp():
    return map(int,input().split())

def sti():
    return str(input())

def par(a):
    print(' '.join(list(map(str,a))))

def tdl(outerListSize,innerListSize,defaultValue = 0):
    return [[defaultValue]*innerListSize for i in range(outerListSize)]

def sts(s):
    s = list(s)
    s.sort()
    return ''.join(s)

def bis(a, x):
    i = bisect_left(a, x) 
    if i != len(a) and a[i] == x: 
        return [i,True]
    else: 
        return [-1,False]

class pair:
    def __init__(self,f,s):
        self.fi = f
        self.se = s
    def __lt__(self,other):
        return (self.fi,self.se) < (other.fi,other.se)

#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

if __name__ == "__main__":
    n,m = isp()
    a = []
    b = []
    c1 = Counter()
    c2 = Counter()
    for i in range(n):
        a.append(iar())
        c1.update(a[i])
    for i in range(n):
        b.append(iar())
        c2.update(b[i])

    for i in range(n):
        for j in range(m):
            if c1[a[i][j]] != c2[a[i][j]]:
                print('NO')
                quit()
    p1 = tdl(n+m,1)
    p2 = tdl(n+m,1)
    for i in range(n):
        for j in range(m): 
            p1[i+j].append(a[i][j])
            p2[i+j].append(b[i][j])
    for i in range(n+m):
        p1[i].sort()
        p2[i].sort()
    #print(p1)
    #print(p2)
    for i in range(n+m):
        if p1[i] != p2[i]:
            print('NO')
            quit()
    print('YES')