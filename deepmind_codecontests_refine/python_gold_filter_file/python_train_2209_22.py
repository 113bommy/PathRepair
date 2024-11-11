"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys,math
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
t = inp()
for tt in range(t):
    n = inp()
    print(((n - 1) // 9) + n)