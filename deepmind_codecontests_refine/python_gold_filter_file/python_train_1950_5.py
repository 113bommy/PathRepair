x, y = map(int, input().split())
if x < 3 or y < 3:
	if x**y < y**x:
		print('<')
	elif x**y == y**x:
		print('=')
	else:
		print('>')
else:
	if x<y:
		print('>')
	elif x>y:
		print('<')
	else:
		print('=')