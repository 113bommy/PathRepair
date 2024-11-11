for i in range(int(input())):
	s = input()
	start = s.find('1');end = s.rfind('1')
	print(s[start:end].count('0')) 