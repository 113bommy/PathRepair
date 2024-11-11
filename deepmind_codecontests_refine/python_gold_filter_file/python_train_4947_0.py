first_integer = input()
second_integer = input()

len_first = len(first_integer)
len_second = len(second_integer)

max_len = max(len_first, len_second)

if len_first < len_second:
	first_integer = '0' * (len_second - len_first) + first_integer
elif len_first > len_second:
	second_integer = '0' * (len_first - len_second) + second_integer
	
for i in range(max_len):
	if first_integer[i] < second_integer[i]:
		print('<')
		exit(0)
	elif first_integer[i] > second_integer[i]:
		print('>')
		exit(0)

print('=')