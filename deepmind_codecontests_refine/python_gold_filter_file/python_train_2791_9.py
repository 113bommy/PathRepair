n,k=map(int,input().split())
a=[int(x) for x in input().split()]
c=0
f=[99999999999]*(n)
f[0]=0
for i in range(n):
    for j in range(i+1,i+k+1):
        if j<n:
            f[j]=min(f[j],f[i]+abs(a[i]-a[j]))
print(f[n-1])