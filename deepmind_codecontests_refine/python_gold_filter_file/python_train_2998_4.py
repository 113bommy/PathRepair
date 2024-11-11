N=int(input())
ans=[-1]*(N-1)
rootLine=[0]*N
numLine=[0]*N
l=[]
for i in range(N-1):
  a,b=map(int,input().split())
  a-=1
  b-=1
  l.append([a,b,i])
l.sort()

for a,b,i in l:
  numLine[a]+=1
  if numLine[a]==rootLine[a]:
    numLine[a]+=1
  ans[i]=numLine[a]
  rootLine[b]=numLine[a]

print(max(ans))
for i in ans:
  print(i)