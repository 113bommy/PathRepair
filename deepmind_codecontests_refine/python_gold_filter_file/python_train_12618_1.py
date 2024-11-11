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
for tt in range(t):
    n = inp()
    a = []
    for i in range(n):
        a.append(inlt())
    while True:
        qw = [(j + q) % 2 for j,q in a]
        if 0 != sum(qw) != len(a):
            print(int(sum(qw)))
            for i,j in enumerate(qw):
                if j:
                    print(i + 1, end = " ")
            print()
            sys.exit()
        a = [((a[i][0] + a[i][1] + qw[i]) / 2, (a[i][0] - a[i][1] + qw[i]) / 2) for i in range(len(a))]