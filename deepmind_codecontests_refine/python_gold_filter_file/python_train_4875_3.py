n,m=map(int,input().split())
l=list(list(map(int,input().split())) for i in range(m))
l=sorted(l, key=lambda x:x[1])

ans=0
count=0

for i in range(m):
  if count<l[i][0]:
    ans+=1
    count=l[i][1]-1
print(ans)
