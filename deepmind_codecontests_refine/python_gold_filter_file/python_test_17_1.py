import sys

# f = open('input.in', 'r')
# input = f.readline
input = sys.stdin.readline

class BIT :
	n = None
	A = None
	def __init__(self, n) :
		self.n = n
		self.A = [0] * (n+5)
	def update(self, x, val) :
		while x <= self.n :
			self.A[x] += val
			x += (x&-x)
	def que(self, x):
		if x == 0:
			return 0
		else :
			return self.A[x]+self.que(x-(x&-x))

	def query(self, x, y):
		# print(x, y)
		return self.que(y) - self.que(x-1)

t = int(input())
for nt in range(t) :
	n = int(input())
	A = [-1e15] + list(map(int, input().split()))
	B = sorted(list(set(A)))
	# print(A, B)
	for i in range(1,n+1) :
		kir, kan = 1, len(B)-1;
		while kir < kan : 
			# print(kir, kan)
			mid = (kir+kan)//2
			if A[i] > B[mid] :
				kir = mid+1
			else :
				kan = mid
		A[i] = kir
	
	ft = BIT(n)
	res = 0
	for x in A[1:] :
		mn = min(ft.query(1,x-1), ft.query(x+1,n))
		
		res += mn
		ft.update(x, 1)
	print(res)

