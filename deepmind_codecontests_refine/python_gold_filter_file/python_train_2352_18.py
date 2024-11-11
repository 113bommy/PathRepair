n,m,k=map(int,input().split())
a=list(map(int,input().split()))
mi=int (1e9)
for i in range(m,n):
    if a[i]<=k and a[i]!=0:
        mi=min(mi,i-m+1)
for i in range(max(0,m-2),-1,-1):
    if a[i]<=k and a[i]!=0:
        mi=min(mi,m-1-i)
print(mi*10)