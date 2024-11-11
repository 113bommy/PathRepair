for _ in range(int(input())):
	n = int(input())
	s = str(input())
	while '()' in s:
		s = s.replace('()','')
	print(len(s)//2)
