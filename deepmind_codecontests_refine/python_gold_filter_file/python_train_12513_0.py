t=lambda:map(int,input().split())
n,m=t()
a=sorted(t())
x,s=[0]*n,0
for i in range(n):s+=a[i];x[i]=s if i<m else s+x[i-m]
print(*x)