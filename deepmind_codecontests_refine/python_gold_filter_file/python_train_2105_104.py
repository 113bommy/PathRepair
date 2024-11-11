n = int(input())
l = input()
c,f = 0,0
if 'L' in l :
	m = l.count("L")
	f = 1
if 'R' in l :
	n = l.count("R")
	c = 1
if f==1 and c==1:
	print(m+n+1)
elif f==1:
	print(m+1)
elif c==1:
	print(n+1)
else:
	print(0)