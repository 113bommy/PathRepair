n,a,b,c=map(int,input().split())
da=[0]*(8001)
da[a]=da[b]=da[c]=1
for i in range(min(a,b,c)+1,n+1):
    if da[i-a]==da[i-b]==da[i-c]==0 and da[i]==0:
        da[i]=0
    else:
        da[i]=max(da[i-a],da[i-b],da[i-c])+1
print(da[n])