N=int(input())
K=int(input())
A=list(map(int,input().split()))
ans=0
for i in range(N):
  ans+=2*min(A[i],K-A[i])
print(ans)