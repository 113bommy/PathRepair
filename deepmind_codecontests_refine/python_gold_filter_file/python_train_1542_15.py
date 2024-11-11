n=int(input())
a=list(map(int,input().split()))
ans=[0]*n
res=[]
for i in range(1,n+1):
    t=sum(ans[n-i:n:n-i+1])%2
    if (t-a[n-i])%2==1:
      ans[n-i]=1
      res.append(n-i+1)
print(sum(ans))
print(*res)