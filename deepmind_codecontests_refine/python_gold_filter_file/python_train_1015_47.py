d=[0]*6**8
n,k,*a=map(int,open(0).read().split())
a=d+a
while n:d[n]=max(d[j]for j in range(n,n+99)if abs(a[-n]-a[-j])<=k)+1;n-=1
print(max(d))