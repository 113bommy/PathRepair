import itertools
n=int(input())
A=[[] for i in range(n)]
for i in range(n):
  r=int(input())
  for j in range(r):
    A[i].append(list(map(int,input().split())))
ans=0
L=list(itertools.product([0,1],repeat=n))
for i in L:
  T=[]
  for num,j in enumerate(i):
    if j==1:
      for k in A[num]:
        T.append(k)
  if all(i[j[0]-1]==j[1] for j in T):
    ans=max(ans,sum(i))
print(ans)