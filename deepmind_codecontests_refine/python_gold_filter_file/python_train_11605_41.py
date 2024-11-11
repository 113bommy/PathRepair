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

a,m = map(int,input().split())
MAX = 100000
no = a
res = False
for i in range(MAX):
    no = no+no%m
    if no%m == 0:
        res = True
        break
print('Yes' if res else 'No')

