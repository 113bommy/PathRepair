from sys import stdin
from collections import deque
#from math import sqrt, floor, ceil, log, log2, log10, pi, gcd, sin, cos, asin
def ii(): return int(stdin.readline())
def fi(): return float(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def fmi(): return map(float, stdin.readline().split())
def li(): return list(mi())
def lsi():
    x=list(stdin.readline())
    x.pop()
    return x
def si(): return stdin.readline()
############# CODE STARTS HERE #############
n, m=mi()
a=[{i} for i in range(n+1)]
v=[True]*(n+1)
for _ in range(m):
    x, y=mi()
    a[x].add(y)
    a[y].add(x)
for i in range(1, n+1):
    if v[i]:
        for j in a[i]:
            if a[i]!=a[j]:
                print('NO')
                exit()
            v[j]=False
#print(a)
print('YES')