def fastio():
	import sys
	from io import StringIO 
	from atexit import register
	global input
	sys.stdin = StringIO(sys.stdin.read())
	input = lambda : sys.stdin.readline().rstrip('\r\n')
	sys.stdout = StringIO()
	register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
# fastio()

MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

l, r = I()
if l - r == 0:
	print(0)
# elif r == l + 1:
# 	print(r^l)
else:
	ans = []
	a = list(format(l, '064b'))
	b = list(format(r, '064b'))
	i = 0
	ll = l
	rr = r
	while a[i] == b[i]:
		i += 1
	for i in range(i, 64):
		if a[i] == '0' and b[i] == '0':
			k = l ^ (2**(64 - i - 1))
			if k <= rr:
				l = k
				a[i] = '1'
		elif a[i] == '1' and b[i] == '1':
			k = r - (2**(64 - i - 1))
			if k >= ll:
				b[i] = '0'
				r = k
	print(l^r)