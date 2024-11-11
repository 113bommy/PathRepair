import sys
import math
import bisect
from collections import deque
 
sys.setrecursionlimit(1000000000)
def input():
    return sys.stdin.readline().strip()
 
def iinput():
    return int(input())
 
def finput():
    return float(input())
 
def tinput():
    return input().split()
 
def rinput():
    return map(int, tinput())
 
def rlinput():
    return list(rinput())
 
def modst(a, s):
    res = 1
    while s:
        if s % 2:
            res *= a
        a *= a
        s //= 2
    return res
 

        
 
def main():

    n = iinput() % 4
    if n == 3:
        print(2, "A")
    if n == 0:
        print(1, "A")
    if n == 1:
        print(0, "A")
    if n == 2:
        print(1, "B")
    
            
         
    
        
    
for i in range(1):
    main()