# AOJ 0270: Modular Query
# Python3 2018.6.26 bal4u

N, Q = map(int, input().split())
tbl = [0]*300005
nmax, tbl[0] = 0, 1
c = list(map(int, input().split()))
for k in c:
	tbl[k] = 1
	if k > nmax: nmax = k
	tbl[k & 1] = 1
	tbl[k & 3] = 1
	tbl[k & 7] = 1
for i in range(Q):
	q = int(input())
	if q > nmax: print(nmax)
	else:
		f = 0
		for k in range(q-1, -1, -1):
			for i in range(k, nmax+1, q):
				if tbl[i]:
					print(k)
					f = 1
					break
			if f: break
