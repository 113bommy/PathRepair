import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n = mint()
	a = list(mints())
	c = [0]*(n+1)
	for i in a:
		c[i] += 1
	r = []
	#print(*a)
	while True:
		ok = True
		for i in range(1,n):
			if a[i-1] > a[i]:
				ok = False
				break
		if ok:
			break
		x = c.index(0)
		if x == n:
			for i in range(0,n):
				if a[i] != i:
					p = i
					break
		else:
			p = x
		#p = min(x, n-1)
		#print(x, p, a[p], n)
		c[a[p]] -= 1
		a[p] = x
		c[x] += 1
		r.append(p+1)
		#print(*a)
	#print(*a)
	print(len(r))
	print(' '.join(map(str,r)))

for i in range(mint()):
	solve()
