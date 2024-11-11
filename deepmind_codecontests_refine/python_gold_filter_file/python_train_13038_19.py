import sys
from math import sqrt
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

t = inp()
res = 0
for i in range(t):
    n,m = invr()
    if m%2 == 0:
        res = int(m/2)*n
    else:
        res = int((m-1)/2)*n+int((n+1)/2)
    print(res)