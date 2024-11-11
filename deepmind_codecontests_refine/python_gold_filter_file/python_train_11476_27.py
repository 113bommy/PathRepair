R=lambda:map(int,input().split())
n,m=R()
a=*R(),
r=n<=m
for i in range(r*n):
 for j in range(i):r=r*abs(a[j]-a[i])%m
print(r+0)