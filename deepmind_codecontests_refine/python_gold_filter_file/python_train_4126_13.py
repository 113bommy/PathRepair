def decnums(n):
	v=[]
	dec=10
	while n>=dec:
		v.append(n%dec)
		n=n//dec
	v.append(n)
	return v

def iscornum(n,c):
	sumnums=sum(decnums(c))
	return n==c+sumnums

n=int(input())
v=[]
delta=len(decnums(n))
for c in range(n-1,n-9*delta,-1):
	if c<=0:
		break
	if iscornum(n,c):
		v.append(c)
print(len(v))
v.sort()
for c in v:
	print(c)