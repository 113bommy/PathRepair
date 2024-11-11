def main():
  import sys
  input=sys.stdin.readline
  h,w,k=map(int,input().split())
  H=range(h)
  W=range(w)
  dp=[[[0]*w for j in H] for i in range(4)]
  for _ in range(k):
    r,c,v=map(int,input().split())
    dp[0][r-1][c-1]=v
  if dp[0][0][0]!=0:
    dp[1][0][0]=dp[0][0][0]
    dp[0][0][0]=0
  for y in H:
    for x in W:
      v=dp[0][y][x]
      dp[0][y][x]=0
      for i in range(4):
        if 0<x:
          if dp[i][y][x]<dp[i][y][x-1]:
            dp[i][y][x]=dp[i][y][x-1]
          if 0<i and v!=0 and dp[i][y][x]<dp[i-1][y][x-1]+v:
            dp[i][y][x]=dp[i-1][y][x-1]+v
        if 0<y:
          if dp[0][y][x]<dp[i][y-1][x]:
            dp[0][y][x]=dp[i][y-1][x]
          if v!=0 and dp[1][y][x]<dp[i][y-1][x]+v:
            dp[1][y][x]=dp[i][y-1][x]+v
  print(max([dp[i][h-1][w-1] for i in range(4)]))
main()