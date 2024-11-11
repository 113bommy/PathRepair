n,k,*a=map(int,open(0).read().split())
r=range(n)
while(min(a)<n)*k:
 k-=1;b=[0]*n*3
 for i in r:t=a[i];b[max(0,i-t)]+=1;b[i-~t]-=1
 for i in r:b[i+1]+=b[i]
 a=b[:n]
print(*a)