h,m = input().split(':')
res = 0
while True:
	if h == m[::-1]:
		break
	res+=1
	yy = int(m)+1
	if yy == 60:
		m = '00'
		yy=int(h)+1
		if yy == 24:
			h = '00'
		else:
			h = str(yy).rjust(2,'0')

	else:
		m = str(yy).rjust(2,'0')
print(res)
