"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys,math,cmath
input = sys.stdin.readline
############ ---- USER DEFINED INPUT FUNCTIONS ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(s[:len(s) - 1])
def invr():
    return(map(int,input().split()))
################################################################
############ ---- THE ACTUAL CODE STARTS BELOW ---- ############
t = 1
for tt in range(t):
    n = inp()
    print(2,3)
    print((1 << 18) - 1,n,0)
    print(1 << 17,(1 << 18) - 1,(1 << 17) - 1)