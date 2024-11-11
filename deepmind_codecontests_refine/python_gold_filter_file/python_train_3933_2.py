import sys; input = sys.stdin.buffer.readline
mod = 998244353; INF = float("inf")
sec = pow(2, mod - 2, mod)

def getlist():
	return list(map(int, input().split()))

class lazySegTree(object):
	# N:処理する区間の長さ
	def __init__(self, N):
		self.N = N
		self.LV = (N - 1).bit_length()
		self.N0 = 2 ** self.LV
		self.data = [0] * (2 * self.N0)
		self.lazybeta = [1] * (2 * self.N0)
		self.lazy = [0] * (2 * self.N0)

	def initialize(self, A):
		for i in range(self.N):
			self.data[self.N0 - 1 + i] = A[i]
		for i in range(self.N0 - 2, -1, -1):
			self.data[i] =( self.data[2 * i + 1] + self.data[2 * i + 2]) % mod

	def gindex(self, l, r):
		L = (l + self.N0) >> 1; R = (r + self.N0) >> 1
		lc = 0 if l & 1 else (L & -L).bit_length()
		rc = 0 if r & 1 else (R & -R).bit_length()
		for i in range(self.LV):
			if rc <= i:
				yield R
			if L < R and lc <= i:
				yield L
			L >>= 1; R >>= 1

	def propagates(self, *ids):
		for i in reversed(ids):
			w = self.lazybeta[i - 1]
			v = self.lazy[i - 1]
			if w == 1 and (not v):
				continue
			val = (v * sec) % mod
			self.lazybeta[2 * i - 1] = (self.lazybeta[2 * i - 1] * w) % mod
			self.lazybeta[2 * i] = (self.lazybeta[2 * i] * w) % mod
			self.lazy[2 * i - 1] = (self.lazy[2 * i - 1] * w + val) % mod
			self.lazy[2 * i] = (self.lazy[2 * i] * w + val) % mod
			self.data[2 * i - 1] = (self.data[2 * i - 1] * w + val) % mod
			self.data[2 * i] = (self.data[2 * i] * w + val) % mod
			self.lazybeta[i - 1] = 1; self.lazy[i - 1] = 0

	def update(self, l, r, b, c):
		*ids, = self.gindex(l, r + 1)
		self.propagates(*ids)
		L = self.N0 + l; R = self.N0 + r + 1
		v = c; w = b
		while L < R:
			if R & 1:
				R -= 1
				self.lazybeta[R - 1] = (self.lazybeta[R - 1] * w) % mod
				self.lazy[R - 1] = (w * self.lazy[R - 1] + v) % mod
				self.data[R - 1] = (self.data[R - 1] * w + v) % mod
			if L & 1:
				self.lazybeta[L - 1] = (self.lazybeta[L - 1] * w) % mod
				self.lazy[L - 1] = (w * self.lazy[L - 1] + v) % mod
				self.data[L - 1] = (self.data[L - 1] * w + v) % mod
				L += 1
			L >>= 1; R >>= 1; v <<= 1
		for i in ids:
			self.data[i - 1] = (self.data[2 * i - 1] + self.data[2 * i]) % mod

	def query(self, l, r):
		self.propagates(*self.gindex(l, r + 1))
		L = self.N0 + l; R = self.N0 + r + 1

		s = 0
		while L < R:
			if R & 1:
				R -= 1
				s += self.data[R - 1]
			if L & 1:
				s += self.data[L - 1]
				L += 1
			L >>= 1; R >>= 1
			s %= mod
		return s

def main():
	N, Q = getlist()
	A = getlist()
	lSeg = lazySegTree(N)
	lSeg.initialize(A)
	for _ in range(Q):
		q = getlist()
		if q[0] == 0:
			null, l, r, b, c = q
			lSeg.update(l, r - 1, b, c)
		else:
			null, l, r = q
			res = lSeg.query(l, r - 1)
			print(res)

if __name__ == '__main__':
	main()


# 5 3
# 1 1 1 1 1
# 0 0 4 10 3
# 0 1 5 20 3
# 1 2 3