N=int(input())
dstb=[1]+[6**i for i in range(1,7)]+[9**j for j in range(1,6)]
DP=[10**5]*(10**5*2)
DP[0]=0
for i in range(N+1):
  for j in dstb:
    DP[i+j]=min(DP[i+j], DP[i]+1)

print(DP[N])
