from math import ceil, log, floor, sqrt
	
def mod_expo(n, p, m):
	"""find (n^p)%m"""
	result = 1
	while p != 0:
		if p%2 == 1:
			result = (result * n)%m
		p //= 2
		n = (n * n)%m
	return result
	
def find_product(n, m, arr):
	"""find |arr i - arr j| mod m"""
	product=1
	if n <= m:
		for i in range(n):
			for j in range(i+1, n):
				 product = (product * abs(arr[i] - arr[j]))%m
		return product
	return 0

def count_tables(l):
	count=0
	l.sort()
	a = l[1]-l[0]
	b = l[2]-l[0]
	if a%3 > 0 and (a%3 + (b - (a - a%3))) >= 3:
		count += 1
	count += l[0] + (2*a)//3
	return int(min(sum(l)/3, l[0] + l[1]))
	
def find_possible_weight(W, arr):
	w = 0
	for i in range(8, 0, -1):
		 count = min(arr[i-1], W//i)
		 w += count * i
		 W -= count * i
		 #print(count)
	return w
	
def find_divisor(a):
	divisors = []
	for i in range(2, min(a, ceil(sqrt(a))+1)):
		if a%i == 0:
			if a/i == i:
				divisors.append(i)
			else:
				divisors.append(i)
				divisors.append(a/i)
	if len(divisors) == 0:
		return -1
	return int(min(divisors))

def find_arr(u, v):
	res = []
	if u%2 != v%2 or u > v:
		return res
	if u == v:
		res = [u]
		return res
	x = (v - u)//2
	if u & x:
		res = [u, x, x]
	else:
		res = [u^x, x]
	return res
	
def get_divisors(n, arr):
	d1 = []
	d2 = []
	for i in range(n):
		spf = find_divisor(arr[i])
		if spf == -1:
			d1.append(-1)
			d2.append(-1)
		else:
			while arr[i]%spf == 0:
				arr[i] /= spf
			if arr[i] != 1:
				d1.append(int(arr[i]))
				d2.append(spf)
			else:
				d1.append(-1)
				d2.append(-1)
	print(*d1, sep=' ')
	print(*d2, sep=' ')
	
def find_max_gcd(a):
	degree = ceil(log(a)/log(2))
	#print(degree)
	m = pow(2, degree)-1
	if a == m:
		return find_divisor(a)
	if a == m + 1:
		m = 2*a - 1
	return m
	
t = 1
#t = int(input())
while t:
	t = t - 1
	#n = int(input()) 
	# a, b, m = map(int, input().split()) 
	u, v = map(int, input().split())
	#l = list(map(int, input().strip().split()))[:n]
	#str1 = input()
	#if no_vacancy(n, l):
	#	print("Yes")
	#else:
	#	print("No")
	#print(count(a, b))
	if u == v and u == 0:
		print(0)
	else:
		res = find_arr(u, v)
		if len(res) == 0:
			print(-1)
		else:
			print(len(res))
			print(*res, sep=" ")
