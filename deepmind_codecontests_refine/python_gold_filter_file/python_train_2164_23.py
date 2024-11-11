import sys
input = sys.stdin.readline
def main():
  n,m,s=map(int,input().split())
  uvab=[list(map(int,input().split())) for _ in range(m)]
  cd=[list(map(int,input().split())) for _ in range(n)]
  g=[[]for _ in range(n)]
  for u,v,a,b in uvab:
    g[u-1].append((v-1,a,b))
    g[v-1].append((u-1,a,b))
  import heapq
  inf=pow(10,21)
  max_s=50*50
  dp=[[inf]*(max_s+1)for _ in range(n)]
  kakutei=[[0]*(max_s+1)for _ in range(n)]
  dp[0][min(s,max_s)]=0
  todo=[[0,0,min(s,max_s)]] # [dp[v][i],v,i]
  heapq.heapify(todo)
  flgs=[0]*n
  flg=0
  ans=[inf]*n
  while flg<n:
    _,v,i=heapq.heappop(todo)
    if kakutei[v][i]==1:
      continue
    kakutei[v][i]=1
    if flgs[v]==0:
      flg+=1
      flgs[v]=1
    c,d=cd[v]
    ans[v]=min(ans[v],_)
    # 両替
    j=min(max_s,i+c)
    if kakutei[v][j]==0:
      dp[v][j]=min(dp[v][j],dp[v][i]+d)
      heapq.heappush(todo,[dp[v][j],v,j])
    # 鉄道
    l=g[v]
    for u,a,b in l:
      if i-a>=0 and kakutei[u][i-a]==0:
        dp[u][i-a]=min(dp[u][i-a],dp[v][i]+b)
        heapq.heappush(todo,[dp[u][i-a],u,i-a])
  print(*ans[1:],sep='\n')
if __name__=='__main__':
  main()
