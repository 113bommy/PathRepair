#------------------Important Modules------------------#

from sys import stdin,stdout
from bisect import bisect_left as bl
from bisect import bisect_right as br

from heapq import *
input=stdin.readline
#prin=stdout.write
from random import sample
t=int(input())
#t=1
from collections import Counter,deque
from math import sqrt,ceil,log2,gcd
#dist=[0]*(n+1)
class DisjSet: 
    def __init__(self, n): 
        # Constructor to create and 
        # initialize sets of n items 
        self.rank = [1] * n 
        self.parent = [i for i in range(n)] 
  
  
    # Finds set of given item x 
    def find(self, x): 
          
        # Finds the representative of the set 
        # that x is an element of 
        if (self.parent[x] != x): 
              
            # if x is not the parent of itself 
            # Then x is not the representative of 
            # its set, 
            self.parent[x] = self.find(self.parent[x]) 
              
            # so we recursively call Find on its parent 
            # and move i's node directly under the 
            # representative of this set 
  
        return self.parent[x] 
  
  
    # Do union of two sets represented 
    # by x and y. 
    def union(self, x, y): 
          
        # Find current sets of x and y 
        xset = self.find(x) 
        yset = self.find(y) 
  
        # If they are already in same set 
        if xset == yset: 
            return
  
        # Put smaller ranked item under 
        # bigger ranked item if ranks are 
        # different 
        if self.rank[xset] < self.rank[yset]: 
            self.parent[xset] = yset 
  
        elif self.rank[xset] > self.rank[yset]: 
            self.parent[yset] = xset 
  
        # If ranks are same, then move y under 
        # x (doesn't matter which one goes where) 
        # and increment rank of x's tree 
        else: 
            self.parent[yset] = xset 
            self.rank[xset] = self.rank[xset] + 1
  
# Driver code 



def f(arr,i,j,d,dist):
    if i==j:
        return 
    nn=max(arr[i:j])
    for tl in range(i,j):
        if arr[tl]==nn:
            dist[tl]=d
            #print(tl,dist[tl])
            f(arr,i,tl,d+1,dist)
            f(arr,tl+1,j,d+1,dist)
    #return dist
            
        
def ps(n):
    cp=0
    while n%2==0:
        n=n//2
        cp+=1
    for ps in range(3,ceil(sqrt(n))+1,2):
        while n%ps==0:
            n=n//ps
            cp+=1
            
    if n!=1:
        return False
    return True


#count=0
#dp=[[0 for i in range(m)] for j in range(n)]
#[int(x) for x in input().strip().split()]
def find_gcd(x, y): 
      
    while(y): 
        x, y = y, x % y 
      
    return x 
          
# Driver Code         
def factorials(n,r):
    #This calculates ncr mod 10**9+7
    slr=n;dpr=r
    qlr=1;qs=1
    mod=10**9+7
    
    for ip in range(n-r+1,n+1):
        qlr=(qlr*ip)%mod
    for ij in range(1,r+1):
        qs=(qs*ij)%mod
    #print(qlr,qs)
    ans=(qlr*modInverse(qs))%mod
    return ans

        
        
def modInverse(b):
    qr=10**9+7
    return pow(b, qr - 2,qr)

tt=[xa**3 for xa in range(0,10**4+1)]
qq=set(tt)
def digits(k,rp):
    n=len(k)
    pq=k[::-1]
    jq=''
    for ij in pq:
        if ij=='1':
            jq+='1'
        elif ij=='2':
            jq+='5'
        
        elif ij=='4' or ij=='7' or ij=='3' or ij=='6' or ij=='9':
            jq+='-'
        elif ij=='5':
            jq+='2'
        
        elif ij=='8':
            jq+='8'
        
        elif ij=='0':
            jq+='0'
    if jq.find('-')!=-1:
        return -1
    else:
        jl=int(jq)
        if jl>=rp:
            return -1
        else:
            return jq
def fr(a,b,h,m):
    kl=int(b)
    kl=(kl+1)%m
    b='0'*(2-len(str(kl)))+str(kl)
    if b=='0'*2:
        kj=(int(a)+1)%h
        a='0'*(2-len(str(kj)))+str(kj)
    return [a,b]
        
    
        
            
        
            

for jj in range(t):
    #n=int(input())
    h,m=[int(x) for x in input().strip().split()]
    #arr=[int(x) for x in input().strip().split()];
    #brr=[int(x) for x in input().strip().split()];brr.sort()
    kq=input().strip()
    
    hrs=h;mins=m
    
    while True:
        if digits(kq[:2],m)!=-1 and digits(kq[3:],h)!=-1:
            print(kq)
            break
        #print(kq)
        klp=fr(kq[:2],kq[3:],h,m)
        kq=klp[0]+':'+klp[1]
        
            
        
    
        
        
        
        
    
    
        
        
        
    
    
    
        
    
    
    
    
    
            
        
        
            
    
    
                
                    
                
                        
                    
            
            
        
                
            
        
    
    
            
    
        
    
    
    
        
        
    
    
            
            
            
        
        
            
        
        
        
    
        
            
            
            
            
    
    
    
            
    
    
        
    
    
    
        
    
    
                   
    
        
                
        
    
        
        
        
        
        
                
    
    
    
    
        
    
    
    
    
        
        
        
        
            
        
    

