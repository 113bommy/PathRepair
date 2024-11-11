t = int(input())
a, b = 0, 0
ans = []
temp =''
for i in range(t):
	d = float(input())
	if d*d-4*d < 0:
		ans.append('N')
	else:
		b = (d+(d*d-4*d)**0.5)/2
		a = d - b
		temp = 'Y ' + str(b) + ' ' + str(a)
		ans.append(temp)
for i in range(t):
	print(ans[i])