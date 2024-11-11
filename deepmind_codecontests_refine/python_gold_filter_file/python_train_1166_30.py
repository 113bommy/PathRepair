t=int(input())
s=int(input())
v=int(input())
j=int(input())
e=int(input())
f=int(input())
sum1=0
if e>f:
	if min(t,j)==j:
		sum1=sum1+(j*e)
	elif t==j:
		sum1=sum1+(j*e)
	else:
		sum1=sum1+(t*e)
		j=j-t
		if min(s,v,j)==j:
			sum1=sum1+(f*j)
		else:
			sum1=sum1+(f*(min(s,v)))
else:	
	if min(s,v,j)==j:
		sum1=sum1+(j*f)
	else:
		if min(s,v,j)==s:
			sum1=sum1+(f*s)
			j=j-s
			sum1=sum1+min(t,j)*e
		elif min(s,v,j)==v:
			sum1=sum1+(f*v)
			j=j-v
			sum1=sum1+min(t,j)*e
print(sum1)