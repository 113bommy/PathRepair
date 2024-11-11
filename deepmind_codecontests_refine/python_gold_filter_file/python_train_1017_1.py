N,K,S=map(int,input().split())
ans=[S]*N
m=10**9
for i in range(N-K):
  ans[i]%=m
  ans[i]+=1
print(*ans)