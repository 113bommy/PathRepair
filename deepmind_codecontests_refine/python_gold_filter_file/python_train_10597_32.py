n,m=map(int,input().split())
a=[]
k=[]
for _ in range(m):
  a.append(list(map(int,input().split()))[0])
  k.append(sum(2**(int(i)-1)for i in input().split()))
inf=float('inf')
dp=2**n*[inf]
dp[0]=0
for i in range(2**n):
  for j in range(m):
    dp[i|k[j]]=min(dp[i|k[j]],dp[i]+a[j])
print(dp[-1]if inf!=dp[-1]else-1)
