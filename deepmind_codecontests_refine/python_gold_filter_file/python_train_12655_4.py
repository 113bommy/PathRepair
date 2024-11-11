n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[None]*n;
b[0]=a[0]
ans=0
for i in range(1,n):
    cnt=max(a[i],k-b[i-1])
    ans+=cnt-a[i]
    b[i]=cnt
print(ans)
print(*b)
