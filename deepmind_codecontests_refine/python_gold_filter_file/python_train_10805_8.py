n=int(input());l=[list(map(int,input().split()))for i in[0]*n];a=[0 for i in[0]*n];d=1;k=n*(n-1)
while sum(a)<k and 0<d<9999:
 L=[0 for i in[0]*n];y=0;d+=1
 for i in range(n):
  if a[i]<n-1:
   x=l[i][a[i]]-1
   if l[x][a[x]]-1==i and L[x]+L[i]<1:
    a[i]+=1;a[x]+=1;L[i]=L[x]=y=1
 d*=y
print([k//2,d-1][d<9999])