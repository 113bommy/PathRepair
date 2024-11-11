H,W,h,w=map(int,input().split())
p=(10**9-1)//(max(h*w-1,1))
m=p*(h*w-1)+1
vec=[[p for i in range(W+1)] for j in range(H+1)]
sm=0
for i in range(1,H+1):
  for j in range(1,W+1):
    if i%h==0 and j%w==0:
      vec[i][j]=-m
    sm+=vec[i][j]
if sm<=0:
  print("No")
else:
  print("Yes")
  for i in range(1,H+1):
    for j in range(1,W+1):
      print(vec[i][j],end=" \n"[j==W])