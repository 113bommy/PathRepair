import itertools
n,c=map(int,input().split())
ld=[list(map(int,input().split())) for i in range(c)]
lc=[list(map(int,input().split())) for i in range(n)]
ct=[[0 for i in range(c)] for i in range(3)]
for i in range(n):
  for j in range(n):
    ct[(i+j+2)%3][lc[i][j]-1]+=1
L=list(itertools.permutations([i for i in range(c)],3))

ans=[]
for i in range(len(L)):
  ct2=0
  for j in range(3):
    for k in range(c):
      ct2+=ld[k][L[i][j]]*ct[j][k]
  ans.append(ct2)
print(min(ans))