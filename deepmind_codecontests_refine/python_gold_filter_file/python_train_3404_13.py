import sys      
import bisect
import math as mt

#input=sys.stdin.readline
#t=int(input())
t=1
mod=10**9+7
for _ in range(t):
    n=int(input())
    #n,k=map(int,input().split())
    l=list(map(int,input().split()))
    mul=1
    d={}
    for i in l:
        d[i]=1
        
    maxi=2*10**9
    ans=1
    a1,a2,a3=0,0,0
    ch=0
    for i in range(n):
        mul=1
        while mul<=maxi and ch==0:
            ans1=1
            if d.get(l[i]+mul,-1)!=-1:
                ans1+=1
                a1=l[i]
                a2=l[i]+mul
                if d.get(l[i]+2*mul,-1)!=-1:
                    ans1+=1
                    a3=l[i]+2*mul
                    ch=1
            ans=max(ans,ans1)        
            if ch:
                break
            
            mul*=2
    if ans==1:
        print(1)
        print(l[0])
    elif ans==2:
        print(2)
        print(a1,a2)
    else:
        print(3)
        print(a1,a2,a3)
        