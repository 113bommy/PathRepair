for _ in range(int(input())):
	n,k=map(int,input().split())
	a=list(map(int,input().split()))
	a1=set(a)
	d=len(a1)
	j=0
	m=0
	tot=0
	while(tot<d and k-(j>0)>0):
		t=k-(j>0)
		tot+=t
		m+=1
		j+=1
	if(tot<d):
		print(-1)
	else:
		print(m)
