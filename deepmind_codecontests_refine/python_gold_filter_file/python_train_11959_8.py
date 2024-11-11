while True:
	n = int(input())
	
	if n == 0:
		break
	
	res = -1111111111
	s = 0
	for i in range(n):
		a = int(input())
		s = max(s + a, a)
		res = max(s, res)
	
	print(res)