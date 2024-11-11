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

n, m, k = I()
l = I()
l.sort()
if n == 1:
	print(l[0])
	exit()
a = l[-1]
b = l[-2]
if m <= k:
	print(m*a)
	exit()
x = a*k + b
print(x*(m//(k+1)) + a*(m%(k+1)))