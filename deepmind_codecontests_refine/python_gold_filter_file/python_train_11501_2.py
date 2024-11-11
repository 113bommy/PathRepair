m, s = input().split()
m = int(m)
s = int(s)
s2=s
min = ''
max = ''
if (m>1 and s==0) or s>9*m:
	print("-1 -1")
else:
	while s >= 9:
		max += '9'
		s -= 9
	if s!=0:
		max += str(s)
	max += '0' * (m - len(max))

	while s2 > 9:
		min += '9'
		s2 -= 9
	if m - len(min) > 1:
		min += str(s2 - 1)
		min += '0' * (m - len(min) - 1)
		min += '1'
	else:
		min += str(s2)
	min=min[::-1]
	print(min ,max)