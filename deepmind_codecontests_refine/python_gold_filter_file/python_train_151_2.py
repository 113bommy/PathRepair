from collections import Counter
from collections import defaultdict

def get_single(a, b):
	res = 2 ** 32
	for s in b.keys():
		res = min(res, a[s] // b[s])
	return res



def get_count(a, b, c):
	best = 0, get_single(a, c)
	r1 = 0
	while a & b == b:
		r1 += 1
		a = a - b
		r2 = get_single(a, c)
		if r1 + r2 > sum(best):
			best = r1, r2
	return best
	

a = input()
b = input()
c = input()
aa = Counter(a)
bb = Counter(b)
cc = Counter(c)

r = get_count(Counter(a), bb, cc)

res = b * r[0] + c * r[1]
rest = aa - Counter(res)
res += ''.join(list(rest.elements()))

print(res)
