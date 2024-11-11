n=int(input())
mod=10**9+7

s1=input()
s2=input()

if n==1:
    print(3)
    exit(0)

if s1[0]==s1[1]:
    l=1
    ans=6
    i=2
else:
    l=0
    ans=3
    i=1

while i<n:
    if i==n-1:
        if l==0:
            ans*=2
            ans%=mod
        break

    if s1[i+1]==s1[i]:
        c=1
        i+=2
    else:
        c=0
        i+=1
    
    if l==0:
        ans*=2
    if l==1 and c==1:
        ans*=3
    
    ans%=mod
    
    l=c
    
print(ans)
