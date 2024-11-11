# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 19:33:34 2017

@author: savit
"""

n=int(input())
a=list(map(int,input().split()))
b=[]
chains=[]
for i in range(n):
    b.append(True)
for i in range(n):
    if(b[i]):
        chains.append([i,])
        j=i
        b[j]=False
        while((a[j]-1)!=chains[-1][0]):
            
            chains[-1].append(a[j]-1)
            
            j=a[j]-1
            b[j]=False
chainlen=list(map(len,chains))
if(len(chains)>1):
    #print("entered")
    
    max1=max(chainlen)
    max1=chainlen.index(max1)
    chainlen[max1]*=-1
    
    max2=max(chainlen)
    max2=chainlen.index(max2)
    #print(max1,max2,chainlen)
    chainlen[max2]=chainlen[max2]+(-1*chainlen[max1])
    del chainlen[max1]
con=0
#print(chains)
#print(chainlen)
for i in chainlen:
    con+=i*i
print(con)        
