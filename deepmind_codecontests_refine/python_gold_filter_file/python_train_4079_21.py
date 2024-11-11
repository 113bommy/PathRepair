def fastio():
	import sys
	from io import StringIO 
	from atexit import register
	global input
	sys.stdin = StringIO(sys.stdin.read())
	input = lambda : sys.stdin.readline().rstrip('\r\n')
	sys.stdout = StringIO()
	register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

t, = I()
m = [[-1, 0], [0, 1], [1, 0], [0, -1]]
while t:
	t -= 1
	n, = I()
	d1 = [10**5, -10**5]
	d2 = [10**5, -10**5]
	for i in range(n):
		x, y, a1, a2, a3, a4 = I()
		if a1 == 0:
			d1[1] = max(d1[1], x)
		if a2 == 0:
			d2[0] = min(d2[0], y)
		if a3 == 0:
			d1[0] = min(d1[0], x)
		if a4 == 0:
			d2[1] = max(d2[1], y)
	if d1[1] > d1[0]:
		print(0)
		continue
	elif d2[1] > d2[0]:
		print(0)
		continue
	else:
		print(1, d1[0], d2[0])


'''
for i in range(n-1):


'''