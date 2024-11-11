n,k=map(int,input().split())

a=n%k
ans=min(a,k-a)
print(ans)