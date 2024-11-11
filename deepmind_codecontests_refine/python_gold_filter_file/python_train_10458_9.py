s = [int(i) for i in input().split()]
c = 0
e = 4
r = 0
for i in range(6):
	a = s.count(s[i])
	if a>c:
		r = s[i]
		c=a
if c<4:
	print("Alien")
else:
	while e>0:
		a = s.index(r)
		del s[a]
		e-=1
	if s[0]==s[1]:
		print("Elephant")
	else:
		print("Bear")