q = int(input())
for _ in range(q):
	s = input()
	d = 0
	l=0
	r=0
	u=0
	for i in s:
		if i == 'L':
			l+=1
		if i == 'D':
			d+=1
		if i == 'U':
			u+=1
		if i == 'R':
			r+=1
	n = len(s) - abs(r-l) - abs(d-u)
	d, u = min(d, u), min(d, u)
	r, l = min(r, l), min(r, l)
	
	if d == 0 and r != 0:
		r = 1
		l = 1
		n = 2
	if r==0 and d!=0:
		d = 1
		u = 1
		n = 2
	print(n)
	print('R'*r + 'D'*d + 'L'*l + 'U'*u)