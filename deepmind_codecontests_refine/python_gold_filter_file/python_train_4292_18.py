import sys
import bisect as bi
import math
from collections import defaultdict as dd
import heapq
import itertools
input=sys.stdin.readline
from random import randint
##import numpy as np
##sys.setrecursionlimit(10**7)
mo=10**9+7
def cin():
    return map(int,sin().split())
def ain():            
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())

for _ in range(inin()):
    k=inin()
    d=dd(int)
    sq=int(math.sqrt(k))+1;c=0;ans=[];f=0
    for i in range(2,sq+1):
        if(k%i==0):
            k=k//i
            c+=1
            ans+=[i]
        if(c==2 and k!=1 and k not in ans):
            f=1
            break
    if(f):
        print("YES")
        print(*ans,k)
    else:print("NO")
            
    
    
        
    
        
        
##    if((n*(n+1)//2)%2):print("NO")
##    else:
##        print("YES")
##        print(n//2)
##        print(l[
        
        
        
    
        
    
        
      

        
        
    
    
    
 
    
    
            
    
        
    
    
    

                    
                    
                    
                    
                    
        
    
    
    
    
            
        

##def msb(n):n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;n|=n>>32;n|=n>>64;return n-(n>>1) #2 ki power
##def pref(a,n,f):             
##    pre=[0]*n
##    if(f==0):         ##from beginning
##        pre[0]=a[0]
##        for i in range(1,n):
##            pre[i]=a[i]+pre[i-1]
##    else:              ##from end
##        pre[-1]=a[-1]
##        for i in range(n-2,-1,-1):
##            pre[i]=pre[i+1]+a[i]
##    return pre
##maxint=10**24 
##def kadane(a,size): 
##    max_so_far = -maxint - 1
##    max_ending_here = 0
##       
##    for i in range(0, size): 
##        max_ending_here = max_ending_here + a[i] 
##        if (max_so_far < max_ending_here): 
##            max_so_far = max_ending_here 
##  
##        if max_ending_here < 0: 
##            max_ending_here = 0   
##    return max_so_far
##def power(x, y):
##    if(y == 0):return 1
##    temp = power(x, int(y / 2))%mo
##    if (y % 2 == 0):return (temp * temp)%mo 
##    else:
##        if(y > 0):return (x * temp * temp)%mo 
##        else:return ((temp * temp)//x )%mo

##for _ in range(1):
##    n=inin()
##    l=ain()
##    d=dd(list)
##    dp=dd(set)
##    for k in range(n):
##        i=l[k]
##        dp[i].add(k)
##        b=bin(i)[2:]
##        c=0
##        for j in b[::-1]:
##            if j=='1':
##                d[c]+=[[i,k]]
##            c+=1
##    key=sorted(list(d.keys()),reverse=True)
##    ans=0
##    for i in key:
##        va=d[i]
##        va.sort(reverse=True)
##        p=len(va)
##        if(p!=0):
##            c=0;tans=0
##            for j,po in va:
##                if(po in dp[j]):
##                    c+=1
##                    f1,f2=j,po
##                    tans+=j
##                    dp[j].remove(po)
##            if(c%2==0 and c!=0):
##                c-=1
##                
##            ans+=tans
##            print(ans,i,c,va)        
##    print(ans)
##        
##        
##    
    
    
    
    
        
        
    
    
    
    


    




##def msb(n):n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;n|=n>>32;n|=n>>64;return n-(n>>1) #2 ki power
##def pref(a,n,f):             
##    pre=[0]*n
##    if(f==0):         ##from beginning
##        pre[0]=a[0]
##        for i in range(1,n):
##            pre[i]=a[i]+pre[i-1]
##    else:              ##from end
##        pre[-1]=a[-1]
##        for i in range(n-2,-1,-1):
##            pre[i]=pre[i+1]+a[i]
##    return pre
##maxint=10**24 
##def kadane(a,size): 
##    max_so_far = -maxint - 1
##    max_ending_here = 0
##       
##    for i in range(0, size): 
##        max_ending_here = max_ending_here + a[i] 
##        if (max_so_far < max_ending_here): 
##            max_so_far = max_ending_here 
##  
##        if max_ending_here < 0: 
##            max_ending_here = 0   
##    return max_so_far
##def power(x, y):
##    if(y == 0):return 1
##    temp = power(x, int(y / 2))%mo
##    if (y % 2 == 0):return (temp * temp)%mo 
##    else:
##        if(y > 0):return (x * temp * temp)%mo 
##        else:return ((temp * temp)//x )%mo

            
        
        
        
            
    
        
        
    
    
    

 
    
    
    
    
        
        
    
    
    
    


    




##def msb(n):n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;n|=n>>32;n|=n>>64;return n-(n>>1) #2 ki power
##def pref(a,n,f):             
##    pre=[0]*n
##    if(f==0):         ##from beginning
##        pre[0]=a[0]
##        for i in range(1,n):
##            pre[i]=a[i]+pre[i-1]
##    else:              ##from end
##        pre[-1]=a[-1]
##        for i in range(n-2,-1,-1):
##            pre[i]=pre[i+1]+a[i]
##    return pre
##maxint=10**24 
##def kadane(a,size): 
##    max_so_far = -maxint - 1
##    max_ending_here = 0
##       
##    for i in range(0, size): 
##        max_ending_here = max_ending_here + a[i] 
##        if (max_so_far < max_ending_here): 
##            max_so_far = max_ending_here 
##  
##        if max_ending_here < 0: 
##            max_ending_here = 0   
##    return max_so_far
##def power(x, y):
##    if(y == 0):return 1
##    temp = power(x, int(y / 2))%mo
##    if (y % 2 == 0):return (temp * temp)%mo 
##    else:
##        if(y > 0):return (x * temp * temp)%mo 
##        else:return ((temp * temp)//x )%mo
