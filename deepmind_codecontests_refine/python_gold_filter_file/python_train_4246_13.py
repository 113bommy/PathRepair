n,m=map(int,input().split())
p=[(i,1)for i in range(n)]
def find(i):
  if p[i][0]==i:return i
  else:
    c=find(p[i][0])
    p[i]=(c,0)
    return c
def union(i,j):
  pi=find(i)
  pj=find(j)
  if not pi==pj:
    if p[pi][1]>p[pj][1]:
      p[pi]=(pi,p[pi][1]+p[pj][1])
      p[pj]=(pi,0)
    else:
      p[pj]=(pj,p[pi][1]+p[pj][1])
      p[pi]=(pj,0)
      

for i in range(m):
  a,b=map(int,input().split())
  union(a-1,b-1)
ans=0
for i in range(n):
  if p[i][0]==i:ans=max(ans,p[i][1])
print(ans)