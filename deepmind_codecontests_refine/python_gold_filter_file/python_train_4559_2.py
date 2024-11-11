a,b,m=map(int,input().split())
at=list(map(int,input().split()))
bt=list(map(int,input().split()))
ans=min(at)+min(bt)
for i in range(m):
  x,y,c=map(int,input().split())
  ans=min(ans,at[x-1]+bt[y-1]-c)
print(ans)
