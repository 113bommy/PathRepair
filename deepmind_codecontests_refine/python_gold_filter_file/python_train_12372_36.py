n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]
ans=0
for i in range(n-1):
  for j in range(i+1,n):
    flg=True
    for k in range(n):
      if k in (i,j):continue
      if a[i][j]>a[i][k]+a[k][j]:
        print(-1)
        exit()
      elif a[i][j]==a[i][k]+a[k][j]:
        flg=False
    if flg:
      ans+=a[i][j]
      #print(i,j)

print(ans)
