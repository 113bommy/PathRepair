
class Card:
	def __init__(self, m, n, o):
		self.m = m
		self.n = n
		self.o = o
	def __str__(self):
		return str(self.m + ' ' + str(self.n))
	
def swap(a, i, j):
	tmp = a[i]
	a[i] = a[j]
	a[j] = tmp

def partition(a, f, c):
	x = a[c].n
	i = f - 1
	for j in range(f, c):
		if a[j].n <= x:
			i += 1
			swap(a, i, j)
	swap(a, i + 1, c)
	return i + 1

def quick_sort(a, f, c):
	if (f < c):
		q = partition(a, f, c)
		quick_sort(a, f, q - 1)
		quick_sort(a, q + 1, c)

def check_stability(a):
	for i in range(1, len(a)):
		c1 = a[i-1]
		c2 = a[i]
		if (c1.n == c2.n and c1.o > c2.o):
			return False
	return True
		
n = int(input())
cards = []
for i in range(n):
	m, num = map(str, input().split())
	cards.append(Card(m, int(num), i))

quick_sort(cards, 0, n - 1)
if (check_stability(cards) == True):
	print('Stable')
else:
	print('Not stable')
for i in range(n):
	print(cards[i])

