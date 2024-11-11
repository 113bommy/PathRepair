n,a,b=map(int,input().split())
ans=a*(n//(a+b))
ans+=min(n%(a+b),a)
print(ans)