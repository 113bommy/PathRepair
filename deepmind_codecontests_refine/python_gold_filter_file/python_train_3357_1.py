import sys
input = sys.stdin.readline
import math as m

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().strip().split()))
    
for _ in range(inp()):
    n, k = invr()
    prod = m.floor(k / (n-1))
    rem = k % (n-1)
    new_ans = prod * n
    if(rem != 0):
        new_ans += rem
    else:
        new_ans -= 1
    print(new_ans)