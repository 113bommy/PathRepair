t = int(input())

for x in range(t) :
	s = input()
	s = input()

	hit1, hit2 = 0, 0
	for i in s :
		if i == '>' :
			break
		hit1 += 1

	s = s[::-1]
	for i in s :
		if i == '<' :
			break
		hit2 += 1
	print(min(hit1,hit2));