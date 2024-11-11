n = int(input())
for i in range(n):
	s = sorted(input())
	if(s[0]==s[-1]):
		print('-1')
	else:
		print(''.join(s))
