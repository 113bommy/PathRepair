a = str(input())
b = ''
for i in a:
	if i in 'AEIYOUaeyiou':
		pass
	else:
		b = b + '.' + i.lower()
print(b)