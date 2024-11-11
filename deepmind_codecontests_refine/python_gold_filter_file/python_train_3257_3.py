"""
ID: happyn61
LANG: PYTHON3
PROB: loan
"""
from itertools import product
import itertools
#from collections import defaultdict
import sys
import heapq
from collections import deque
MOD=1000000000007
#fin = open ('loan.in', 'r')
#fout = open ('loan.out', 'w')
#print(dic["4734"])
def find(parent,i):


    if parent[i] != i: 
        parent[i]=find(parent,parent[i]) 
    return parent[i] 

        # A utility function to do union of two subsets 
def union(parent,rank,xx,yy): 
    x=find(parent,xx)
    y=find(parent,yy)
    if rank[x]>rank[y]:
        parent[y]=x
    elif rank[y]>rank[x]:
        parent[x]=y
    else:
        parent[y]=x
        rank[x]+=1
ans=0
#NK=sys.stdin.readline().strip().split()
K=int(sys.stdin.readline().strip())
#N=int(NK[0])
#K=int(NK[1])
#M=int(NK[2])
for testj in range(K):
    WK=sys.stdin.readline().strip().split()
    W=int(WK[1])
    l=list(map(int,sys.stdin.readline().strip().split()))
    ll=[]
    kk=0
    for i in range(len(l)):
        if l[i]<=W:
            ll.append((l[i],i+1))
            kk+=l[i]
    #print(kk,ll,W)
    ll.sort()
    if len(ll)==1:
        if ll[0][0]*2>=W and ll[0][0]<=W:
            print("1")
            print(ll[0][1])
        else:
            print("-1")
    elif kk*2<W:
        print("-1")
    else:
        F=False
        for i in range(len(ll)):
            if ll[i][0]<=W and ll[i][0]*2>=W:
                F=True
                print("1")
                print(str(ll[i][1]))
                
                break
        
        if not F:
            F=False
            k=0
            ans=[]
            for i in range(len(ll)):
                k+=ll[i][0]
                ans.append(str(ll[i][1]))
                #print(i,k,"asd")
                if k*2>=W:
                    if k<=W:
                        print(len(ans))
                        print(" ".join(ans))
                        #print(k,W)
                        F=True
                        break
                    else:
                        print(k,W)
                        print("-1")
                        F=True
                        break
            if not F:
                print("-1")
