def prod(n):
	res = 1
	while n:
		res *= (n % 10)
		n //= 10
	return res
		

string = input()
if (len(string) == 1):
	print(string)
else:
	trad = str(int(string[0])-1)
	n = len(string)
	for i in range(n-1):
		trad += '9'
	s = ''
	for i in range(n-1):
		if string[i] > string[i+1]:
			s += str(int(string[i])-1)
			break
		s += string[i]

	for i in range(n - len(s)):
		s += '9'

	num = int(s)
	if (num > int(string)):
		num = 0
	ans = max(prod(int(trad)), prod(num), prod(int(string)))
	print(ans)
