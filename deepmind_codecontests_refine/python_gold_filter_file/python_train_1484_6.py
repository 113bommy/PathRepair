from sys import stdin,stdout
from collections import defaultdict,Counter 
input=stdin.buffer.readline


prime = [True for i in range(200000 + 1)] 

def SieveOfEratosthenes(): 
      
    # Create a boolean array "prime[0..n]" and initialize 
    # all entries it as true. A value in prime[i] will 
    # finally be false if i is Not a prime, else true. 
    
    p = 2
    while (p * p <= 200000): 
          
        # If prime[p] is not changed, then it is a prime 
        if (prime[p] == True): 
              
            # Update all multiples of p 
            for i in range(p * 2, 200000 + 1, p): 
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False


SieveOfEratosthenes()

v1=[-1 for i in range(200000 + 1)] 
v2=[-1 for i in range(200000 + 1)] 





n=int(input())
a=list(map(int,input().split()))
res=1
for p in range(2,200000+1):
    if prime[p]:
        v1=-1
        v2=-1
        for x in a:
            nn=x
            value=0
            
            while nn%p==0:
                nn//=p
                value+=1
            if v1 ==-1 and v2 ==-1:
                v2 =value
            elif v1 ==-1:
                if v2 ==value:
                    v1 =value
                elif v2 <value:
                    v1 =v2 
                    v2 =value
                else:
                    v1 =value
            elif value<v2  and value>=v1 :
                v2 =value
            elif value<v1 :
                v2 =v1 
                v1 =value
            
            if v1==0 and v2==0:
                break
    
        res*=(p**v2)


print(res)




