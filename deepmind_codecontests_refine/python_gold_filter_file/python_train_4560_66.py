n,k=map(int,input().split())
arr1=list(map(int,input().split()))
arr1=sorted(arr1)
arr2=list(map(int,input().split()))
arr2=sorted(arr2,reverse=True)
l=-1
r=10**12+1
while r-l!=1:
  m=(r+l)//2
  tmp=0
  for i in range(n):
    if arr1[i]>m//arr2[i]:
      tmp+=(arr1[i]-m//arr2[i])
  if tmp<=k:
    r=m
  else:
    l=m
print(r)