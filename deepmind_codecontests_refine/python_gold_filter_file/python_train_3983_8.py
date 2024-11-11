n,m=map(int,input().split())
ans=1
mod=998244353
a=list(map(int,input().split()))
b=list(map(int,input().split()))
i=n-1
j=m-1
while ans and j>=0:
    cnt=0
    while i>=0 and a[i]>=b[j]:
        if cnt:cnt+=1
        elif a[i]==b[j]:cnt=1
        i-=1
    if j==0:
        cnt=min(cnt,1)
        if i>=0:cnt=0
    ans=(ans*cnt)%mod
    j-=1
print(ans)