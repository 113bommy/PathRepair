n,k=map(int,input().split())
a=[(2*k+1)*[0]for _ in range(2*k+1)]
for _ in range(n):
  x,y,c=input().split()
  x=int(x)
  y=int(y)
  if c=="B":y+=k
  x%=2*k
  y%=2*k
  a[x+1][y+1]+=1
ans=0
for i in range(1,2*k+1):
  for j in range(1,2*k+1):a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1]
for i in range(k,2*k+1):
  for j in range(k,2*k+1):
    t=a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]
    t+=a[i-k][j-k]
    t+=a[2*k][j-k]-a[i][j-k]
    t+=a[i-k][2*k]-a[i-k][j]
    t+=a[2*k][2*k]-a[i][2*k]-a[2*k][j]+a[i][j]
    ans=max(ans,t,n-t)
print(ans)