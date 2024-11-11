h,w=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(2*h)]
board=[[0]*w for _ in range(h)]
for i in range(h):
  for j in range(w):
    board[i][j]+=arr[i][j]
for i in range(h):
  for j in range(w):
    board[i][j]=abs(board[i][j]-arr[h+i][j])
dp=[[set() for _ in range(w)] for _ in range(h)]
dp[0][0].add(board[0][0])
for i in range(h):
  for j in range(w):
    if i!=0:
      for k in dp[i-1][j]:
        dp[i][j].add((k+board[i][j])%800)
        dp[i][j].add(abs(k-board[i][j])%800)
    if j!=0:
      for k in dp[i][j-1]:
        dp[i][j].add((k+board[i][j])%800)
        dp[i][j].add(abs(k-board[i][j])%800)
print(min(dp[h-1][w-1]))