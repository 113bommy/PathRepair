import sys
sys.setrecursionlimit(10**8)
INF = float("inf")

def findsum(li):

    for i in range(1,len(li)+1):
        tot[i]=tot[i-1]+li[i-1]
    #print(tot)

def findans(start,end,li):
  global tot
  #print("HI")
  if(start>=end):
    return 0
  if(dp[start][end]!=-1):
    return dp[start][end]
  ans = INF
  for k in range(start,end):


      ans=min(findans(start,k,li)+findans(k+1,end,li),ans)
  dp[start][end]=ans+(tot[end+1]-tot[start])
  return dp[start][end]
n=int(input())
li=[int(k) for k in input().split()]
tot=[0]*(len(li)+1)
findsum(li)
dp=[[-1 for i in range(n)]for k in range(n)]
print(findans(0,n-1,li))
