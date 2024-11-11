n=int(input())
arr=[list(input()) for _ in range(n)]
ans=0
for k in range(n):
  flag=True
  for i in range(1,n//2+1):
    for j in range(n):
      if arr[(j)%n][(k+j+i)%n]!=arr[(j+i)%n][(k+j+n)%n]:
        flag=False
        break
    if flag==False:
      break
  else:
    ans+=n
print(ans)