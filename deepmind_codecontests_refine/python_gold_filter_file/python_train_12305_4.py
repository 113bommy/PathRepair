p=[[1,0]]
k=1
n=1000000000000000000
s=0
while k<=n:
	k=k*3
	s+=p[-1][0]
	p.append([k,s])
t=int(input())
p.reverse()
for _ in range(t):
	n=int(input())
	f=0
	m=n
	a=0
	k=[]
	for i in p:
		if i[0]>n:
			if a==0:
				k=i.copy()
		else:
			a=1
			n=n-i[0]
		if k!=[]:
			if k[1]-i[0]>=m:
				k[1]-=i[0]
		if n==0:
			f=1
			break
	if f==0:
		if k[1]<k[0] and m<=k[1]:
			m=k[1]
		else:
			m=k[0]
	print(m)