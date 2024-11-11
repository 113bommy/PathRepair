import bisect
n,k=map(int,input().split())
a=list(map(int,input().split()))
c0=[0]*n
if a[0]==0:
  c0[0]+=1
for i in range(1,n):
  c0[i]+=c0[i-1]
  if a[i]==0:
    c0[i]+=1
ans=0
idx=0
for i in range(n):
  if k>=c0[i]:
    if ans<i+1:
      ans=i+1
      idx=0
  else:
    l=bisect.bisect_left(c0,c0[i]-k)+1
    if ans<i-l+1:
      idx=l
      ans=i-l+1
arr=[]
for i in range(idx):
  arr.append(a[i])
for i in range(idx,idx+ans):
  arr.append(1)
for i in range(idx+ans,n):
  arr.append(a[i])
print(ans)
print(*arr)