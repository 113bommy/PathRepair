d=[0]*6**8
n,k,*a=map(int,open(0).read().split()+d)
while n:n-=1;d[n]=max(d[j]for j in range(n,n+99)if~k<a[n]-a[j]<=k)+1
print(max(d))