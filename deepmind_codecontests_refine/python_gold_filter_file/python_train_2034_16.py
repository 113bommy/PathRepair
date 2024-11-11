def f():
	a = int(input())
	if a <= 127 and a >= -128:
		print('byte')
	elif a <= 32767 and a >= -32768:
		print('short')
	elif a <= 2147483647 and a >= -2147483648:
		print('int')
	elif a <= 9223372036854775807 and a >= -9223372036854775808:
		print('long')
	else:
		print('BigInteger')
f()