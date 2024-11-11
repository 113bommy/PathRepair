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

n, v = I()
if v >= n:
	print(n-1)
	exit()
d = v
dist = v + 1
r = n - dist
print((r+1)*(r+2)//2 - 1 + v)