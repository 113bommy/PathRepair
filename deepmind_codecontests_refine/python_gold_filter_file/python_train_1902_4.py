import sys
import math as mt
import bisect
from collections import Counter, deque
from heapq import heappush, heappop
input=sys.stdin.readline
t=int(input())
#t=1
mod=998244353
def ncr_util():
    inv[0]=inv[1]=1
    fact[0]=fact[1]=1
    for i in range(2,300001):
        inv[i]=(inv[i%p]*(p-p//i))%p
    for i in range(1,300001):
        inv[i]=(inv[i-1]*inv[i])%p
        fact[i]=(fact[i-1]*i)%p
def check(x):
    c=Counter(l)
    #print(c)
    que=[]
    l1=deque()
    for val,cnt in c.items():
        heappush(que,(-cnt,val))
    while que:
        cnt,val=heappop(que)
        cnt=-cnt
        cnt-=1
        l1.append((cnt,val))
        if len(l1)>=x:
            cnt,val=l1.popleft()
            if cnt:
                heappush(que,(-cnt,val))
    for cnt,val in l1:
        if cnt:
            return False
    return True
            
        
        
    
for _ in range(t):
    n=int(input())
    #n1=int(input())
    #s=input()
    #n=int(input())
    #n,k=(map(int,input().split()))
    #n1=n
    #a=int(input())
    #b=int(input())
    #a,b,c,r=map(int,input().split())
    #x2,y2=map(int,input().split())
    #n=int(input())
    #s=input()
    #s1=input()
    #p=input()
    l=list(map(int,input().split()))
    #l2=list(map(int,input().split()))
    #l=str(n)
    #l.sort(reverse=True)
    #l2.sort(reverse=True)
    #l1.sort(reverse=True)
    r=n
    le=0
    ans=0
    while r-le>1:
        mid=(le+r)//2
        if(check(mid)):
            #ans=max(ans,mid)
            le=mid
        else:
            r=mid
    print(le-1)    