import collections

n=int(input())
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
cnt1=collections.Counter(arr1)
cnt2=collections.Counter(arr2)
acum1=[0]*(n+1)
acum2=[0]*(n+1)
for i in range(1,n+1):
  acum1[i]=acum1[i-1]+cnt1[i]
  acum2[i]=acum2[i-1]+cnt2[i]
rotate=0
for i in range(1,n+1):
  rotate=max(rotate,acum1[i]-acum2[i-1])
ans=[0]*n
for i in range(n):
  ans[(i+rotate)%n]=arr2[i]
for i in range(n):
  if arr1[i]==ans[i]:
    print('No')
    break
else:
  print('Yes')
  print(*ans)