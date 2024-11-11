from collections import defaultdict
n=int(input())
a1=list(map(int,input().split()))
p=[0 for _ in range(n+1)]
a=[0 for _ in range(n+1)]
for i in range(1,n+1):
	a[i]=a1[i-1]
for i in range(1,n+1):
	p[i]=p[i-1]+a[i]
ans=0
for i in range(1,n):
	ans=ans+p[n]-2*p[i]
c=0
# print(ans)
d = defaultdict(int)
d[a[n]]+=1
for i in range(n-1,0,-1):
	d[a[i]]+=1
	if(d[a[i]+1]>0):
		ans-=d[a[i]+1]
	if(d[a[i]-1]>0):
		ans+=d[a[i]-1]
print(ans)