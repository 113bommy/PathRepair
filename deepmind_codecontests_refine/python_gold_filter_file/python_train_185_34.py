import collections
import math

n, p = [int(i) for i in input().split()]
d = collections.defaultdict(lambda: 0)

def bunkai(q):
	if q == 1:
		return 0
	for i in range(2, math.ceil(math.sqrt(p))):
		if q % i == 0:
			d[i] += 1
			return bunkai(q//i)

if n == 1 or p == 1:
	print(p)
else:
	bunkai(p)
	ans = 1

	for j in d.keys():
		k = d[j]
		if k // n >= 1:
			ans *= j**(k//n)
	print(ans)