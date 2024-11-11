n=int(input())
s=input().strip()
a=[0]*(n+5)
a2=[0]*(n+5)
mn=[0]*(n+5)
mn2=[0]*(n+5)
for i in range(1,n+1,1):
    if s[i-1]=='(':
        a[i]=a[i-1]+1
    else:
        a[i]=a[i-1]-1
    mn[i]=min(mn[i-1],a[i])
    
for i in range(n,0,-1):
    if s[i-1]==')':
        a2[i]=a2[i+1]+1
    else:
        a2[i]=a2[i+1]-1
    mn2[i]=min(mn2[i+1],a2[i])
ans=0
if a[n]!=2 and a[n]!=-2:
    print(0);
    exit(0)
for i in range(1,n+1,1):
    if s[i-1]=='(' and a[n]==2:
        if mn[i-1]>=0 and mn2[i+1]>=0 and a[i-1]>=1:
            ans=ans+1
    elif s[i-1]==')' and a[n]==-2:
        if mn[i-1]>=0 and mn2[i+1]>=0 and a2[i+1]>=1:
            ans=ans+1
        
print(ans)
    
