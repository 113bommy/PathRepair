def fu(r,a,n):
    e=0
    while r<n-1:
        if a[r+1]==0:
            e+=1
        r+=1
        if e==2:
            r-=1
            break
    return r
n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
l=0
r=-1
c=0
for i in range(n):
    if a[i]==0:
        c=c+1
    if c<=k:
        r=i
    else:
        break
b=[[r-l+1,l,r]]
for i in range(n):
    if a[i]==0:
        r=fu(r,a,n)
        l=i+1
        b.append([r-l+1,l,r])
    else:
        l=i+1
        b.append([r-l+1,l,r])
c=max(b)
for i in range(n):
    if c[1]<=i<=c[2]:
        a[i]=1
print(c[0])
print(*a)