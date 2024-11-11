import sys

lst = list(sys.stdin.read())

try:
	lst.remove('\n')
except:
	pass

count = 0
vowels = set(['i', 'e', 'a', 'o', 'u'])
for item in lst:
	try:
		i = int(item)
		if i % 2 == 1:
			count += 1
	except:
		s = str(item)
		if s in vowels:
			count += 1

print(count)