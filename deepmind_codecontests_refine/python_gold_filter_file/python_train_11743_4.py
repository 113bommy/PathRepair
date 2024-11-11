def examA():
    N = DI()/dec(7)
    ans = N
    print(N)
    return

def examB():
    ans = 0
    print(ans)
    return

def examC():
    ans = 0
    print(ans)
    return

def examD():
    N = I()
    n = (N-1).bit_length()
    V = [[-1]*(1<<n) for i in range(1<<n)]
    #print(V)
    for i in range(n):
        b1 = 1 << i
        b2 = 1 << (i + 1)
        for j in range(1<<i):
            for k in range(1<<(n-i)):
                for l in range(1<<(n-i)):
                    #print(i,j,k,l,j+k*b2,j+b1+l*b2)
                    if j+k*b2>=N or j+b1+l*b2>=N:
                        continue
                    u,v = sorted([j+k*b2,j+b1+l*b2])
                    #print(u,v)
                    V[u][v-1] = i+1
    ans = [[]for _ in range(N-1)]
    for i in range(N-1):
        for v in V[i]:
            if v>=0:
                ans[i].append(v)
    for v in ans:
        print(" ".join(map(str,v)))
    return

def examE():
    ans = 0
    print(ans)
    return

def examF():
    ans = 0
    print(ans)
    return

def test():
    i = I()
    li = LI()
    lsi = LSI()
    si = LS()
    print(i)
    print(li)
    print(lsi)
    print(si)
    return

from decimal import getcontext,Decimal as dec
import sys,bisect,itertools,heapq,math,random
from copy import deepcopy
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
def I(): return int(input())
def LI(): return list(map(int,sys.stdin.readline().split()))
def DI(): return dec(input())
def LDI(): return list(map(dec,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet,_ep
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
_ep = dec("0.000000000001")
alphabet = [chr(ord('a') + i) for i in range(26)]
alphabet_convert = {chr(ord('a') + i): i for i in range(26)}

getcontext().prec = 28

sys.setrecursionlimit(10**7)

if __name__ == '__main__':
    examD()

"""
142
12 9 1445 0 1
asd dfg hj o o
aidn
"""