# binary search answer
# O((nm+4^m)logA)
import sys
reader = (s.rstrip() for s in sys.stdin)
inp = reader.__next__

n, m = map(int, inp().split())
arr = tuple(tuple(map(int, inp().split())) for i in range(n))
lower_bound = 0
upper_bound = int(1e9) + 1
mask = (1 << m) - 1

ans = (0, 0)


def can_upper(mid):
	global ans
	""" return exist answer that >= m (boolean)
	O(nm + 4^m)
	"""
	# O(nm)
	d = dict()
	for i in range(n):
		bit = 0
		for j in range(m):
			if arr[i][j] >= mid:
				bit += 1 << j
		d[bit] = i

	# O(m * (2^m)^2) = O(4^m)
	keys = tuple(d.keys())
	for i in range(len(keys)):
		a1 = keys[i]
		for j in range(i, len(keys)):
			a2 = keys[j]
			if a1 | a2 == mask:
				ans = (d[a1], d[a2])
				return True
	return False


while upper_bound - lower_bound > 1:
	middle = (upper_bound + lower_bound) >> 1
	if can_upper(middle):
		lower_bound = middle
	else:
		upper_bound = middle

print(ans[0] + 1, ans[1] + 1)