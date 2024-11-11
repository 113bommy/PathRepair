from collections import defaultdict as dd
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
x,k,y=map(int,input().split())
la=list(map(int,input().split()))
lb=list(map(int,input().split()))
lol=0
if(y*k<x):
    #print(y*k,x)
    lol=1
j=0
ind=[]
for i in range(n):
    if(j==m):
        break
    if(la[i]==lb[j]):
        ind.append(i)
        j+=1
if(j!=m):
    print(-1)
else:
    #print(ind)
    l=la
    ans=0
    curr=ind[0]
    flag=0
    le=ind[0]
    mx=0
    for j in range(0,ind[0]):
        mx=max(mx,l[j])
    if(lol==1):
        if(mx<l[ind[0]]):
            ans+=le*y
        else:
            if(le and le<k):
                flag=1
            elif(le):
                ans+=(le-k)*y+x
    else:
        if(le and le<k):
            if(mx<l[ind[0]]):
                ans+=le*y
            else:
                flag=1
        else:
            rem=le%k
            ans+=rem*y
            ans+=(le//k)*x
    #print(le,ans)
    #print(lol)
    for i in range(1,len(ind)):
        le=ind[i]-curr-1
        mx=0
        for j in range(curr+1,ind[i]):
            mx=max(mx,l[j])
        if(lol==1):
            if(mx<l[curr] or mx<l[ind[i]]):
                #print("lol")
                ans+=le*y
                #print("lol",ans,le,y)
            else:
                #print("lol")
                if(le and le<k):
                    flag=1
                    break
                elif(le):
                    ans+=(le-k)*y+x
        else:
            #print("lol")
            if(le and le<k):
                if(mx<l[ind[i]] or mx<l[ind[i]]):
                    #print(mx)
                    ans+=le*y
                else:
                    flag=1
                    break
            else:
                rem=le%k
                ans+=rem*y
                ans+=(le//k)*x
        curr=ind[i]
        #print(le,ans)
    le=n-1-ind[-1]
    #print(le)
    mx=0
    for j in range(ind[-1]+1,n):
        mx=max(mx,l[j])
    if(lol==1):
        if(mx<l[ind[-1]]):
            ans+=le*y
        else:
            if(le and le<k):
                flag=1
            elif(le):
                ans+=(le-k)*y+x
    else:
        #print("lol")
        if(le and le<k):
            if(mx<l[ind[-1]]):
                ans+=le*y
            else:
                flag=1
        else:
            rem=le%k
            ans+=rem*y
            ans+=(le//k)*x

    if(flag):
        print(-1)
    else:
        print(ans)
        
                
    