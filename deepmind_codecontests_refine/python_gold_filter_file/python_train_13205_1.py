N,A,B=map(int,input().split())
v=list(map(int,input().split()))
v.sort(reverse=True)
a=v[:A]
b=v[:B]
avg=sum(a)/A
print(avg)
c=[[0]*51 for _ in range(51)]
c[0][0]=1
for i in range(50):
  c[i+1][0]=1
  c[i+1][i+1]=1
  for j in range(i):
    c[i+1][j+1]=c[i][j]+c[i][j+1]
if a[0]==a[-1]:
  ans=0
  x=v.count(a[0])
  for i in range(A,B+1):
    if i<=x:
      ans+=c[x][i]
else:
  x=v.count(a[-1])
  y=a.count(a[-1])
  ans=c[x][y]
print(ans)