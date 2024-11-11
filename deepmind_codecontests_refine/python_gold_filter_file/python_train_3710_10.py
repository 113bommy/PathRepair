a, b, c=input().split()
a, b, c=int(a), int(b), int(c)
d, e=input().split()
d, e=int(d), int(e)
f=[]
while d>0:
	if a>e or d-b<=0:
		d=d-b
		f.append('STRIKE')
	else:
		a=a+c
		f.append('HEAL')
	if d>0:
		a=a-e

print(len(f))
for i in range(len(f)):
	print(f[i])