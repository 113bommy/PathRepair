n,m,k=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

asum=[0]
bsum=[0]

for i in range(n):
  asum.append(asum[i]+A[i])
  
for j in range(m):
  bsum.append(bsum[j]+B[j])

ans=0
ko=m
for i in range(n+1):
  if asum[i]>k:
    break
  while asum[i]+bsum[ko]>k:
    ko-=1
  ans=max(ans,i+ko)
  
print(ans)
