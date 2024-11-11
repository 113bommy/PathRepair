from collections import deque, Counter, OrderedDict
from heapq import nsmallest, nlargest
from math import ceil,floor,log,log2,sqrt,gcd,factorial,pow,pi

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
    s1 = sti()
    s2 = sti()
    h1 = int(s1[:2])
    h2 = int(s2[:2])
    m1 = int(s1[3:])
    m2 = int(s2[3:])

    if h2 == 0:
        if h1 != 0:
            h2 = 24

    h3 = (h1+h2)//2
    h2 = (h1+h2) % 2
    x = -1
    if h2 == 1:
        x = 30
    else:
        x = 0
    m = (m1+m2)//2 + x
    if m >= 60:
        h3 += 1
        m -= 60
    h = str(h3).zfill(2)
    m = ":" + str(m).zfill(2)
    print(h+m)