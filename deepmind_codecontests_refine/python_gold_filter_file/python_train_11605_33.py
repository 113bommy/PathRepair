import sys
a,m = input().split()
a = int(a)
m = int(m)
r = []
e = 0
c = 0
while (e not in r):
	e = a%m
	a+=e
	if e == 0:
		print("Yes")
		sys.exit()
	c+=1
	if c == 1000000:
		break
print("No")