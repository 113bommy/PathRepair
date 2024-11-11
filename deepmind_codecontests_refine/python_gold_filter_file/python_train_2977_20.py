n,k=map(int,input().split())
l=[]
for i in range(2,n+1):
	if n%i==0:
		while n%i==0 and len(l)<(k-1):
			n//=i
			l.append(i)
if n>1:
	l.append(n)
if len(l)==k:
	print(*l)
else:
	print(-1)