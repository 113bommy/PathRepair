n,W=map(int,input().split())
mv=1
s=[None]*n
for i in range(n):
  s[i]=list(map(int,input().split()))
  mv+=s[i][1]
  
INF=10**9+5
dp=[INF]*mv
dp[0]=0
for i in range(len(s)):
  w=s[i][0]
  v=s[i][1]
  for j in range(len(dp)-v-1,-1,-1):
    if dp[j]+w<dp[j+v]:
      dp[j+v]=dp[j]+w
      
ans=0
for i in range(len(dp)):
  if dp[i]<=W:
    ans=i
    
print(ans)