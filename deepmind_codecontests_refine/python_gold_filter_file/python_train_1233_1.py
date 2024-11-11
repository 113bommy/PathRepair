N=int(input())
a=[input() for i in range(N)]
blackExistCol=[False for i in range(N)]
blackNumRow=[0 for i in range(N)]


flag=False
Max=-1
already=0

for i in range(N):
  for j in range(N):
    if a[i][j]=="#":
      blackExistCol[j]=True
      blackNumRow[i]+=1
      flag=True

if flag==False:
  print("-1")
else:
  for i in range(N):
    if blackExistCol[i]:
      if Max<blackNumRow[i]:
        Max=blackNumRow[i]
  Min=N-Max
  for j in range(N):
    for i in range(N):
      if a[i][j]==".":
        break
    else:
      already+=1
  temp=max(blackNumRow)
  Min2=N-temp+1
  
  ans=min(Min,Min2)+N-already
  
  print(ans)