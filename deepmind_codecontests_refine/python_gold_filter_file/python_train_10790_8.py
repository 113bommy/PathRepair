x=[int(z) for z in input().split()]

l=x[0]
r=x[1]
a=x[2]
if l>r :
	r_0=r+a
	if r_0>l:
		r_0=l
		print(r_0*2+(int((abs(a-(l-r)))/2)*2))
	else:
		print(r_0*2)	
if r>l:
	l_0=l+a
	if l_0>r:
		l_0=r

		print(l_0*2 +(int((abs(a-(r-l)))/2)*2) )
	else:
		print(l_0*2)
if l==r:
	print((l+int(a/2))*2)





