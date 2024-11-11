H,W=list(map(int,input().split()))
A=[list(map(int,input().split())) for _ in range(H)]

ans=[]
for y in range(H):
  for x in range(W-1):
    if A[y][x]%2==1:
      A[y][x]-=1
      A[y][x+1]+=1
      ans.append([y+1,x+1,y+1,x+2])

for i in range(H-1):
  if A[i][-1]%2==1:
    A[i][-1]-=1
    A[i+1][-1]+=1
    ans.append([i+1,W,i+2,W])

print(len(ans))
for i in ans:
  print(*i)
