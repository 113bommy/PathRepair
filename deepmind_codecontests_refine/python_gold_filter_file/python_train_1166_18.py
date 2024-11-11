def func(l,z,comm,e,f):
	lmin=min(l)
	zmin=min(z)
	sum=0
	if f>e:
		sum=f*(zmin)+e*(min(comm-zmin,l[0]))
	else:
		sum=e*(lmin)+f*(min(z[0],z[1],comm-lmin))
	return sum


a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())

print(func([a,d],[b,c,d],d,e,f))