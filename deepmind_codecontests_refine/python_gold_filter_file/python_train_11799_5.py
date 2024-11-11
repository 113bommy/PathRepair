#_________________ Mukul Mohan Varshney _______________#

#Template
import sys
import os
import math
import copy
from math import gcd
from bisect import bisect
from io import BytesIO, IOBase
from math import sqrt,floor,factorial,gcd,log,ceil
from collections import deque,Counter,defaultdict
from itertools import permutations, combinations

#define function 
def Int(): return int(sys.stdin.readline())
def Mint(): return map(int,sys.stdin.readline().split())
def Lstr(): return list(sys.stdin.readline().strip())
def Str(): return sys.stdin.readline().strip()
def Mstr(): return map(str,sys.stdin.readline().strip().split())
def List(): return list(map(int,sys.stdin.readline().split()))
def Hash(): return dict()
def Mod(): return 1000000007
def Ncr(n,r,p): return ((fact[n])*((ifact[r]*ifact[n-r])%p))%p
def Most_frequent(list): return max(set(list), key = list.count)
def Mat2x2(n): return [List() for _ in range(n)]
def btod(n): 
    return int(n,2) 
    
def dtob(n): 
    return bin(n).replace("0b","")    

 
# Driver Code 	
def solution():
     #for _ in range(Int()):
          n,t=Mint()
          ans=[]
          for i in range(n):
               x,y=Mint()
               ans.append([2*x-y,2*x+y])
          mukul=2
          ans.sort()
          for i in range(1,len(ans)):
               
               res=(ans[i][0]-ans[i-1][1])
               #print(res)
               if(res>2*t):
                    mukul+=2
               elif(res==2*t):
                    mukul+=1
          print(mukul)          

               
#Call the solve function          
if __name__ == "__main__":
     
     solution()  