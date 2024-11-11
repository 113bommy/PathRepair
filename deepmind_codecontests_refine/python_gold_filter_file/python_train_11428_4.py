n,x,m=map(int,input().split())
p=[x]
A=set([x])
f=0
for i in range(n-1):
	p.append(p[-1]**2%m)
	if p[-1] in A:
		f=1
		break
	else:
		A.add(p[-1])
if f==0:
	print(sum(p))
else:
	for i in range(len(p)):
		if p[i]==p[-1]:
			loop=len(p)-i-1
			break
	SUM=sum(p[i:-1])
	ans=sum(p)-p[-1]
	n-=len(p)-1
	ans+=SUM*(n//loop)+sum(p[i:i+n%loop])
	print(ans)