N = int(input())
A = []
for i in range(N):
  h,p = list(map(int, input().split()))
  A.append([h+p,h,p])
  
A.sort()

# N人積んだ時の最小の高さH
dp = [-1 for i in range(N+1)]
dp[0] = 0

for i in range(N):
  _,h,p = A[i]
  for j in range(N, 0, -1):
    ## まだj-1人積んだことがない
    if dp[j-1] < 0:
      continue
    ## 高すぎてつめない
    if dp[j-1] > h:
      continue
    if dp[j] < 0:
      dp[j] = dp[j-1] + p
    else:
      dp[j] = min(dp[j], dp[j-1] + p)
    
for i in range(N+1):
  if dp[i] < 0:
    print(i-1)
    exit(0)

print(N)
