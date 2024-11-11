n,l=[int(x) for x in input().split()]
light=list(map(int,input().split()))
light.sort()
m=0
if len(light)==1:
	print("%.9f" % max(light[0]-0,l-light[0]))
else:
	for i in range(len(light)-1):
		a=light[i+1]-light[i]
		if m<=a:
			m=a
	b=round(m/2,9)
	c=max(light[0]-0,b,l-light[-1])
	print("%.9f" % c)
