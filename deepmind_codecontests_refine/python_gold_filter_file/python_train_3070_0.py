def flip(c):
	if(c == '1'):
		return '0'
	else:
		return '1'

s = input()
t = input()

c = list(s)

b = []

n = len(s)
m = 0

for i in range(n):
	if(s[i] != t[i]):
		m += 1
		b.append(i)

if(m % 2 == 1):
	print('impossible')
else:
	x = m//2
	for i in range(x):
		y = b[i]
		c[y] = flip(c[y])
	print(''.join(c))