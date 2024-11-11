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
from math import log2, ceil
from bisect import bisect_right as br, bisect_left as bl
from collections import Counter as C

n, k = I()
l = I()
l.sort()
if n == 1:
	print(l[0] + k)
	exit()
m = l[n//2]
l += [10**18]
a = n//2
for i in range(a, n+1):
	if (i - a)*(l[i] - m) <= k:
		# print(a-i, i)
		k -= (i - a)*(l[i] - m)
		m = l[i]
	else:
		print(m+k//(i - a))
		break