n,k=map(int,input().split())
l=list(map(int,input().split()))

for i in range(k,n):
  if l[i] > l[i-k]:
    print('Yes')
  else:
    print('No')
