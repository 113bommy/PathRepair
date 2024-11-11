n=int(input())
L=list(map(int,input().split(' ')))
i=0
if len(L)<1:
  print(0)
else:
  while i+1<len(L) and L[i]<=L[i+1]:
    i=i+1
  j=i+1
  k=0
  
  while j<len(L) and L[j]<=L[0] and L[j]<=L[(j+1)%n]:
    j=j+1
    k=k+1
  if j!=n:
    print(-1)
  else:
    print(k)
  