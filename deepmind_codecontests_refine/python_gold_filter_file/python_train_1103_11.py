'''input
3
11
'''
k, n = int(input()), sorted(map(int, list(input())))
c = 0
s = sum(n)
for x in n:
	if s < k:
		s += 9 - x
		c += 1
	else:
		break
print(c)

