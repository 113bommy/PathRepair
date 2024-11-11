n,k=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a[:k])
for i in range(n-k):
	t=s-a[i]+a[k+i]
	print('YNeos'[s>=t::2])
	s=t