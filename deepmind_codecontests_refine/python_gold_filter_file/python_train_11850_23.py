n,m=map(int,input().split())
ans=1
for i in range(1,int(m**(1/2))+1):
    if m%i==0:
        if i>=n:ans=max(m//i,ans)
        if m//i>=n:
            ans=max(i,ans)
print(ans)