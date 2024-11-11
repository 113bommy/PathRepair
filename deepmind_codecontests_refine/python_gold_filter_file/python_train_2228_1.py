(a,b)=map(int,input().split())
c=list(map(int,input().split()))
c.sort(reverse=True)
d=[]
if a==b:
	print(c[0]-c[b-1])
else:
	for i in range(b-a+1):
		e=c[i]-c[i+a-1]
		d.append(e)
	d.sort()
	print(d[0])
	
