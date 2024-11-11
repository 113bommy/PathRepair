s = input()

s = [i for i in s if i != ' ' and i != '?']

if s[len(s) - 1].lower() in ['a', 'e', 'i', 'o', 'u', 'y']:
	print('YES')
else:
	print('NO') 