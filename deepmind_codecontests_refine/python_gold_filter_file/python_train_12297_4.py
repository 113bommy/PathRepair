q=int(input())
for i in range(q):
	l,r=map(int,input().split())
	x=0
	if(l%2!=0 or r%2!=0):
		x=1
	o=((r-l)//2)+x
	e=(r-l+1)-(o)
	if(l%2==0):
		h1=(e*(2*l+(e-1)*2))//2
		h2=(o*(2*(l+1)+(o-1)*2))//2
		print(int(h1-h2))
	elif(l%2!=0):
		h1=(e*(2*(l+1)+(e-1)*2))//2
		h2=(o*(2*(l)+(o-1)*2))//2
		print(int(h1-h2))
