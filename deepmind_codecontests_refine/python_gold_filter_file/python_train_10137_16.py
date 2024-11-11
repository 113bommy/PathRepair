def sc(s,n):
	"""special converter"""
	if n<4:
		return s
	l,t=n,''
	if n%2:
		l=n-3
		t=''.join(('-',s[-3:]))
	v=[s[c:c+2] for c in range(0,l,2)]
	return '-'.join(v)+t

n=int(input())
print(sc(input(),n))