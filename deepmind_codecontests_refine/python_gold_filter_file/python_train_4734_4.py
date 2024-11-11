b=list(input().split())
c=b[-1]
d='AEIOUY'
d1='aeiouy'
if c=='?':
	c=b[-2]
	if c[-1] in d or c[-1] in d1:
		print('YES')
	else:
		print('NO')
else:
	if c[-2] in d or c[-2] in d1:
		print('YES')
	else:
		print('NO')
	
