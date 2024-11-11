c,b,n=map(int,input().split())
if n%2==0:
	p=int(n/2)
	s=p%b
	if s==0:
		s=s+b
	if n%(2*b)==0:
		x=int(n/(2*b))
	else:
		x=int(n/(2*b))+1
	print(x ,s,"R")
else:
	p=int(n/2)+1
	s=p%b
	if s==0:
		s=s+b
	if n%(2*b)==0:
		x=int(n/(2*b))
	elif n%(2*b)>0:
		x=int(n/(2*b))+1
	print(x ,s,"L")