import sys
input=sys.stdin.readline
sys.setrecursionlimit(1000000000)
n=int(input())
a=list(map(int,input().split()))
b=[0]
for i in a:b.append(i+b[-1])
dp=[n*[10**15]for _ in range(n)]
def dfs(l,r):
  if dp[l][r]!=10**15:return dp[l][r]
  if l==r:return 0
  dp[l][r]=b[r+1]-b[l]+min(dfs(l,i)+dfs(i+1,r)for i in range(l,r))
  return dp[l][r]
print(dfs(0,n-1))