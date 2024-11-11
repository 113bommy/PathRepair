a  =  int(input())

b = list(map(int,input().split()))

b.sort()

c = 1
d = 0
dd = 0

p = b[0]

for i in range(1,a):
	if p == b[i]:
		c += 1
	elif p != b[i]:
		p = b[i]
		c = 1
	if c == 2:
		d = dd
		dd = p
	elif c == 4:
		d = p
		dd = p

print(d*dd)