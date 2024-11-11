from sys import stdin, stdout
import itertools as it
from math import sqrt
n = int(stdin.readline())
def f(n, k):
	if n % k != 0:
		return set()
	def ec(n, k):
		tk = int (n / k)
		s = (tk * (tk + 1)) >> 1
		return int(k * s - (k - 1) * tk)
	return set([ec(n,k), ec(n, int(n / k))])
ans = set()
for i in range(1, int(sqrt(n)) + 2):
	ans.update(f(n,i))
ans.update(f(n,n))
for a in sorted(ans, reverse = False):
	stdout.write('{} '.format(a))
