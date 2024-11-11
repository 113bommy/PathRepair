import time
start = time.time()
H,W=[int(s) for s in input().split()]
inls=[[int(s) for s in input().split()] for _ in range(H)]
for i in range(H):
  x=[int(s) for s in input().split()]
  for j in range(W):
    inls[i][j]=abs(inls[i][j]-x[j])
dp=[[set() for _ in range(W)] for _ in range(H)]
dp[0][0].add(inls[0][0])
for i in range(H):
  for j in range(W):
    x=80*(H+W-i-j)
    for e in dp[i-1][j]:
      if e+inls[i][j]<x:
        dp[i][j].add(e+inls[i][j])
      dp[i][j].add(abs(e-inls[i][j]))
    for e in dp[i][j-1]:
      if e+inls[i][j]<x:
        dp[i][j].add(e+inls[i][j])
      dp[i][j].add(abs(e-inls[i][j]))
  if time.time() - start>1.7:
    dp[H-1][W-1].add(0)
    break
print(min(dp[H-1][W-1]))
