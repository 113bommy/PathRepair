n,m,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
aa,bb=[0],[0]
for i in range(n):
    aa.append(aa[-1]+a[i])
for i in range(m):
    bb.append(bb[-1]+b[i])
ans,j=0,m
for i in range(n+1):
    if aa[i]>k:
        break
    while bb[j]>k-aa[i]:
        j-=1
    ans=max(ans,i+j)
print(ans)