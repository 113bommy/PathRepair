s = input()

c = 0
m = 0
for i in s:
	if i in 'ACGT':
		c += 1
		m = max(c,m)
	else:
		c = 0

print(m)