from itertools import permutations
n,m,rl=map(int,input().split());r=list(map(int,input().split()))
d=[[float("inf")for _ in range(n)]for _ in range(n)]
for i in range(m):
  x,y,z=map(int,input().split())
  d[x-1][y-1],d[y-1][x-1]=z,z
for i in range(n):d[i][i]=0
for k in range(n):
  for i in range(n):
    for j in range(n):d[i][j]=min(d[i][j],d[i][k]+d[k][j])
a=float("inf")
for i in permutations(r,rl):
  aa=0
  for j in range(rl-1):aa+=d[i[j]-1][i[j+1]-1]
  a=min(a,aa)
print(a)
