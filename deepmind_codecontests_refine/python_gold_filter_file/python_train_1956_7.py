n,k=map(int,input().split())
ans=n%k
print(min(ans,abs(ans-k)))