n=int(input())
s=[]
for i in range(n):
	r=str(input())
	s.append(r[0])
r=set(s)
p=list(r)
l=[]
c=0
for i in range(len(p)):
	l.append(s.count(p[i]))
for i in range(len(l)):
	if l[i]%2==0:
		o=int(l[i]/2)
		for i in range(1,o):
			r=o-i
			c+=2*r
	else:
		o=int(l[i]/2)
		p=o+1
		for i in range(1,o):
			r=o-i
			c+=r
		for i in range(1,p):
			m=p-i
			c+=m
print(c)
