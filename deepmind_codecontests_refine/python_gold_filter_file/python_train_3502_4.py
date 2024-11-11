
n,m=map(int,input().split())
l=[]
for i in range(n):
	l+=input().split()
for i in range(m):
	a,b=input().split()
	c=list(b)
	c.remove(c[-1])
	c="".join(c)
	print(a+" "+b+" #"+l[l.index(c)-1])