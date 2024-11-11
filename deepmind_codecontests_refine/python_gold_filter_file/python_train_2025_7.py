n=int(input())
a=list(map(int,input().split()))
prev=0
j=0
for i in range(n):
	if(prev>a[i]):
		j=i
		break
	prev=a[i]
na=a[j:]+a[:j]
if na==sorted(a):
	print((n-j)%n)
else:
	print(-1)
