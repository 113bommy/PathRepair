import math

T = int(input())
for i in range(T):
	s,i,e = (int(x) for x in input().split())
	d = (i+e-s) / 2
	if d.is_integer():
		d = int(d+1)
	else:
		d = math.ceil(d)
	if d <= 0:
		print(e+1)
	elif d > e:
		print('0')
	else:
		print(e-d+1)
