import math
import sys
n,b=list(int(i) for i in input().split())
#we need to find power of b in n!
#n=10**18
#b=10**12
def primefactorizaton(b):
    i=2
    p=[]
    while(b%i==0):
       p.append(2)
       b//=2
    for i in range(3,int(math.sqrt(b))+1,2):
        if b%i==0:
            while(b%i==0):
                p.append(i)
                b//=i
    if b>2:
        p.append(b)
    return p 
def powr(r,s,n):
    w=r
    alpha=0
    while(n//w!=0):
        alpha+=n//w 
        w*=r  
    alpha//=s  
    return alpha 
        
    
X=primefactorizaton(b)
dict={}
for ele in X:
    if ele not in dict:
        dict[ele]=1 
    else:
        dict[ele]+=1 
#print(dict) 
ans=10**25
for ele in dict:
    ans=min(ans,powr(ele,dict[ele],n))
print(ans)
