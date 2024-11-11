N,K=map(int,input().split())
H=list(map(int,input().split()))
DP=[0]*(N)
DP[0]=0
DP[1]=abs(H[1]-H[0])
for i in range(2,N):
  DP[i]=min([abs(H[i]-H[k])+DP[k] for k in range(max(i-K,0),i)])
print(DP[N-1])