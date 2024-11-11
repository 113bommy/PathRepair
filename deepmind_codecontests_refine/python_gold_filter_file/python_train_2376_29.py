h,w=map(int,input().split())
l=[list(map(int,input().split())) for i in range(h)]

ct=0
ans=[]

for i in range(h):
  for j in range(w-1):
    if l[i][j]%2==1:
      ans.append([i+1,j+1,i+1,j+2])
      ct+=1
      l[i][j+1]+=1
for k in range(h-1):
  if l[k][w-1]%2==1:
    ans.append([k+1,w,k+2,w])
    ct+=1
    l[k+1][w-1]+=1

print(ct)
for i in range(ct):
  print(ans[i][0],ans[i][1],ans[i][2],ans[i][3])