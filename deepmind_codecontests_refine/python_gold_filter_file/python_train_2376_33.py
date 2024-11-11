H,W = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(H)]
#print(A)

ans = []
for i in range(H):
  for j in range(W-1):
    if A[i][j] % 2 == 1:
      A[i][j] -= 1
      A[i][j+1] += 1
      ans.append([i+1,j+1,i+1,j+2])
for i in range(H-1):
  if A[i][W-1] % 2 == 1:
    A[i][W-1] -= 1
    A[i+1][W-1] += 1
    ans.append([i+1,W,i+2,W])
print(len(ans))
for a in ans:
  print(*a)
