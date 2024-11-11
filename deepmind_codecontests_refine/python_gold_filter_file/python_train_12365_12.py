n,k=map(int,input().split())
arr=list(map(int,input().split()))
for i in range(k,n):
  if arr[i]>arr[i-k]:
    print('Yes')
  else:
    print('No')