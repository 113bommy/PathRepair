import itertools
n,m,x=list(map(int,input().split()))
ans=10**18
A=[list(map(int,input().split())) for i in range(n)]
for i, _ in enumerate(A,1):
  for j in itertools.combinations(A,r=i):
    B=list(zip(*j))
    
    C=[0]*(m+1)
    for m in range(m+1):
      C[m]=sum(B[m])
    if len([i for i in C[1:] if i>=x ])==m:
      ans=min(ans,C[0])
print(ans) if ans!=10**18 else print(-1)