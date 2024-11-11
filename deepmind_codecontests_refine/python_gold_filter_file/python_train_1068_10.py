import sys
import random
from fractions import Fraction
from math import *
 
def input():
    return sys.stdin.readline().strip()
 
def iinput():
    return int(input())

def finput():
    return float(input())

def tinput():
    return input().split()

def linput():
    return list(input())
 
def rinput():
    return map(int, tinput())

def fiinput():
    return map(float, tinput())
 
def rlinput():
    return list(map(int, input().split()))
def trinput():
    return tuple(rinput())

def srlinput():
    return sorted(list(map(int, input().split())))

def NOYES(fl):
    if fl:
        print("NO")
    else:
        print("YES")
def YESNO(fl):
    if fl:
        print("YES")
    else:
        print("NO")
    
def main():
    #n = iinput()
    #k = iinput() 
    #m = iinput() 
    #n = int(sys.stdin.readline().strip()) 
    n, k = rinput()
    #n, m = rinput()
    #m, k = rinput()
    #n, k, m = rinput()
    #n, m, k = rinput()
    #k, n, m = rinput()
    #k, m, n = rinput() 
    #m, k, n = rinput()
    #m, n, k = rinput()
    #q = rlinput()
    #q = linput()
    q = len(set(rlinput()))
    if k == 1:
        print(-1 if q != 1 else 1)
        return 0
    print((k - 2 + max(q - k, 0)) // (k - 1) + 1)
        

            
        
    
                
    
    
    
            
    
        
    

for i in range(iinput()):
    main()
