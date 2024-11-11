a = int(input().strip())

imin = max(0, a - 81)

l = []

for i in range(imin, a):
	x = list(str(i))
	s = 0
	for xx in x:
		s += int(xx)
	if s + i == a:
		l.append(i)

print(len(l))
for e in l:
	print(e)
