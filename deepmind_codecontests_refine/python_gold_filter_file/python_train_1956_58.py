n,k=map(int,input().split())
n=n%k
ans=min(n,k-n)
print(ans)