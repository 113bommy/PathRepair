def z_function(s,z):
    n=len(s)
    
    l,r,k=0,0,0
    for i in range(1,n):
        if(i>r):
            l,r=i,i
            while r<n and s[r-l]==s[r]:
                r+=1
            z[i]=r-l
            r-=1
        else:
            k=i-l
            if(z[k]<r-i+1):
               z[i]=z[k]
            else:
                l=i
                while r<n and s[r-l]==s[r]:
                    r+=1
                z[i]=r-l
                r-=1

import sys
input=sys.stdin.readline
t=int(input())
def solve(ss,res):
    
    mx=0
    #print(ss)
    z=[0]*len(ss)
    z_function(ss,z)
    #print(ss)
    #print(z)
    ls=len(z)
    for i in range(len(z)-1,-1,-1):
        #print(z[i],ls-i+1)
        if(z[i]==ls-i):
            mx=max(mx,z[i])
    #print(mx)
    for i in range(mx):
        res.append(ss[i])
    nn=len(res)
    for i in range(nn-mx-1,-1,-1):
        res.append(res[i])
    return "".join(res)

while t:
    
    res1=[]
    res2=[]
    s=input().split()[0]
    n=len(s)
    if(n==1):
        print(s)
    else:
        i=0
        j=n-1
        while i<j:
            if(s[i]==s[j]):
                res1.append(s[i])
                res2.append(s[i])
            else:
                break
            i+=1
            j-=1
        ss=s[i:j]
        ss=ss+'*'+ss[::-1]
        s1=solve(ss,res1)
        ss=s[i:j+1]
        ss=ss[::-1]+'*'+ss
        s2=solve(ss,res2)
        if(len(s1)>=len(s2)):
            print(s1)
        else:
            print(s2)
    t-=1