import itertools
n=int(input())
la=[]
for _ in range(n):
  d=int(input())
  for dd in range(d):
    x,y=map(int,input().split())
    la.append([_,x-1,y])
ans=0
for i in itertools.product([0,1],repeat=n):
  s=sum(list(i))
  for l in la:
    if i[l[0]]==1 and i[l[1]]!=l[2]:
      break
  else:
    ans=max(ans,s)
print(ans)