n,m=map(int,input().split())
l=[input() for i in range(n)]
c=0
for i in l:
	a,d,*b=i
	b=int("".join(b))
	
	if(a=="+"):
		m+=int(b)
	else:
		if(m-int(b)<0):
			c+=1
		else:
			m-=int(b)
print(m,c)
