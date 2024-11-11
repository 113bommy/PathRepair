s, v1, v2, t1, t2 = map(int, input().split())
if s * v1 + t1 * 2 < s * v2 + t2 * 2:
	print('First')
elif s * v1 + t1 * 2 > s * v2 + t2 * 2:
	print('Second')
else:
	print('Friendship')
