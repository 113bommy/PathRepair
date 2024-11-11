n=int(input())
a=list(map(int,input().split()))
ans=[0 for i in range(n)]
ans[0]=a[0]
for i in range(1,n):
    ans[i]=ans[i-1]+(i+1)*(a[i]-1)+1
print(ans[n-1])