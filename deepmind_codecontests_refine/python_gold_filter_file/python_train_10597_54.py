inf=10**8

n,m=map(int,input().split())

A=[]
C=[]
dp=[inf]*(1<<n)
dp[0]=0

for _ in range(m):
  a,_=map(int,input().split())
  c=list(map(int,input().split()))
  A.append(a)
  tmp=0
  for i in c:
    tmp+=1<<(i-1)
  C.append(tmp)

for i in range(1<<n):
  for index,j in enumerate(C):
    dp[i|j]=min(dp[i|j],dp[i]+A[index])
ans=dp[-1]
if ans==inf:ans=-1
print(ans)