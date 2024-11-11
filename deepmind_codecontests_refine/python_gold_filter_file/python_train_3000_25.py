N,M=map(int,input().split())
l=list(map(int,input().split()))
w=[2,5,5,4,5,6,3,7,6]
l.sort()
dp=[0]*(max(N+1,8))
for j in l:
   dp[w[j-1]]=j
for i in range(N):
   if dp[i]!=0:
      for j in l:
         if w[j-1]+i<=N:
            dp[i+w[j-1]]=max(dp[i+w[j-1]],dp[i]*10+j)
print(dp[N])