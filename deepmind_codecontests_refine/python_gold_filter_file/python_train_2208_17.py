import re
t = int(input())
while t:
	text = input()
	s1 = set()
	s2 = set()
	for m in re.finditer('one',text):
		s1.add((m.start(), m.end()))
	for m in re.finditer('two',text):
		s2.add((m.start(), m.end()))

	# print(s1)
	# print(s2)
	soln = []
	for i in s1:
		if (i[0]-2, i[0]+1) in s2:
			s2.remove((i[0]-2, i[0]+1))
			soln.append(i[0]+1)
		else:
			soln.append(i[1]-1)

	for i in s2:
		soln.append(i[1]-1)

	print(len(soln))
	for i in soln:
		print(i, end = " ")
	print()
	t-=1

