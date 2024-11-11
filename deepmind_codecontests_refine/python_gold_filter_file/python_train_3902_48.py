'''input
9 9
'''

n, m = map(int, input().split())

n -= 2

print("#"*m)
flag = True
while n > 0:
	if flag:
		print('.'*(m-1) + '#')
		print("#"*m)
		flag = False
		n -= 2
	else:
		print('#' + '.'*(m-1))
		print("#"*m)
		flag = True
		n -= 2

