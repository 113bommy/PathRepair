n,a,b=map(int,input().split())
ans=a*(n//(a+b))
ans+=min(a,n%(a+b))
print(ans)