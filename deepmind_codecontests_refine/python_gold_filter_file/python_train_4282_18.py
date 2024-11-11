n,s=map(int,input().split())
v=list(map(int,input().split()))
if sum(v)<s:
	print("-1")
else:
	p=min(v)
	k=0
	for i in v:
		if i>p:
			k+=i-p
	if k>=s:
		print(p)
	else:
		x=s-k
		if x%n==0:
			print(p-x//n)
		else:
			print(p-x//n-1)
