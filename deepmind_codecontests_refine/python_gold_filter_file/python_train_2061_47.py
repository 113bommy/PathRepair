import re
a = input()
b = re.compile('^([^L][^R])*[^L]?$')
if b.match(a):
	print('Yes')
else:
	print('No')
