from math import *
t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    ans=-1
    if a==b:
        ans=0
    else:
        if b>a:
            a,b=b,a
        k=a%b
        if k!=0:
            pass
        else:
            c=a//b
            while c>1:
                if c%8==0:
                    if ans==-1:
                        ans=0
                    ans=ans+1
                    c=c//8
                elif c%4==0:
                    if ans==-1:
                        ans=0
                    ans=ans+1
                    c=c//4
                elif c%2==0:
                    if ans==-1:
                        ans=0
                    ans=ans+1
                    c=c//2
                else:
                    ans=-1
                    break
    print(ans)
    
        
                    
                    
                
    