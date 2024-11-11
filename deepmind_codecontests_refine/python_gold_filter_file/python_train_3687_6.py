n,k=map(int,input().split())
arr=[0]
arr+=list(map(int,input().split()))
for i in range(k,n+1):
    arr[i]+=arr[i-k]
ans=n
m=10**9
for i in range(n,n-k,-1):
    if(arr[i]<=m):
        m=arr[i]
        ans=i
ans%=k
if(ans==0):
    ans=k
print(ans)