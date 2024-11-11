n,m=map(int,input().split())
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
arr2=sorted(arr2)
ans=0
for j in arr1:
  l=0
  r=m-1
  res=int(2e9)
  while l<=r:
    mid=(l+r)//2
    if arr2[mid]<j:
      l=mid+1
    else:
       r=mid-1
    res=min(res,abs(arr2[mid]-j))
  ans=max(ans,res)
print(ans)
