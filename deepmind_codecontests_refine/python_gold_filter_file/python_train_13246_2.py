#include <CodeforcesSoutions.h>
"""
    Author : thekushalghosh
    Team   : CodeDiggers

    I prefer Python language over the C++ language :p :D
        
    Visit my website : thekushalghosh.github.io
"""
import sys,math,cmath,time
start_time = time.time()
tt = 0
################# ---- USER DEFINED INPUT FUNCTIONS ---- #################
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    return(input().strip())
def invr():
    return(map(int,input().split()))
##########################################################################
################# ---- THE ACTUAL CODE STARTS BELOW ---- #################

def solve():
    n = inp()
    a = inlt()
    q = [0] * len(a)
    w = 0
    for i in range(len(a) // 2,-1,-1):
        qw = 0
        for j in range((2 * i) + 1,n,i + 1):
            if a[j] > a[i]:
                qw = max(qw,q[j] + 1)
        q[i] = qw
        w = max(w,qw)
    print(w + 1)
                
################## ---- THE ACTUAL CODE ENDS ABOVE ---- ##################
##########################################################################
def main():
    if not ONLINE_JUDGE:
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    t = 1
    t = inp()
    for tt in range(t):
        solve()
    if not ONLINE_JUDGE:
        print("Time Elapsed :",time.time() - start_time,"seconds")
    sys.stdout.close()
############## ---- USER DEFINED PROGRAMMING FUNCTIONS ---- ##############
def counter(a):
    q = [0] * max(a)
    for i in range(len(a)):
        q[a[i] - 1] = q[a[i] - 1] + 1
    return(q)

def string_counter(a):
    q = [0] * 26
    for i in range(len(a)):
        q[ord(a[i]) - 97] = q[ord(a[i]) - 97] + 1
    return(q)
ONLINE_JUDGE = __debug__
if ONLINE_JUDGE:
    input = sys.stdin.readline
    
main()
