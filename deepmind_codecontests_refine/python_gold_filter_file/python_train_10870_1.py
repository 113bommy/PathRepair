from math import log10

w,m,k = map(int,input().split())
d = 0
z = int(log10(m))
zlom = 10**z
while w > 0 :
	z+=1
	zlom*=10
	c = (zlom-m)*z*k
	if c > w :
		x = w//(z*k)
		d+=x
		break
	w-=c
	d+=(zlom-m)
	m = zlom
print(d)
