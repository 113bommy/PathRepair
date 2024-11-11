n,k=map(int,input().split())
l=list(map(int,input().split()))
ki=i=s=0; po=1
for j in range(n):
  s+=(l[j]==0)
  while s>k: s-=(l[i]==0); i+=1
  if j-i>ki-po: po,ki=i,j
print(ki-po+1)
l[po:ki+1]=[1]*(ki-po+1)
print(' '.join(map(str,l)))