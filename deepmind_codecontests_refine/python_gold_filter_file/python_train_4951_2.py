sz = int(input())

odd_no = 1
even_no = 2

for z in range(sz):
	for q in range(sz):
		if ((z + q) >= (sz//2) and (z+q <= (sz//2 + sz-1)) and ((q-z) <= sz//2) and ((z-q) <= sz//2)):
			print(odd_no, end = ' ')
			odd_no+=2
		else:
			print(even_no, end = ' ')
			even_no +=2
	print("")
	