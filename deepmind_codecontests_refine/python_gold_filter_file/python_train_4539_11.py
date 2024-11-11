source_text = input()

count = source_text.count('VK')

if 	source_text.count('VVV') != 0 or \
	source_text.count('KKK') != 0 or \
	source_text[0:2]=='KK' or \
	source_text[-2:]=='VV':
	count += 1

print(count)