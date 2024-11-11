s, v1, v2, t1, t2 = map(int, input().split())
first = 2 * t1 + s * v1
second = 2 * t2 + s * v2
#print(first, second)
if first < second:
	print('First')
elif first > second:
	print('Second')
else:
	print('Friendship')
