source_text = input()
count = source_text.count('VK')
source_text = source_text.replace('VK', '-')
if 	'VV' in source_text or 'KK' in source_text:
	count += 1
print(count)