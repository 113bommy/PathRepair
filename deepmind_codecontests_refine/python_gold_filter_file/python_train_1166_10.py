a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
an = 0
w = 0
if f>e:
	min1 = min(b , c , d)
	an = min1*f
	d = d - min1
	if d>0:
		min2 = min(a , d)
		w = e*min2		
elif e>=f:
	min1 = min(a , d)
	an = min1*e
	d = d - min1
	if d>0:
		min2 = min(b , c , d)
		w = f*min2
print(an+w)		