# Problem: C. Паприка и перестановка
# Contest: Codeforces - Codeforces Round #761 (Div. 2)
# URL: https://codeforces.com/contest/1617/problem/C
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import bisect

mod = 10 ** 9 + 7
eps = 10 ** -9


def __gcd(a, b):
	return a if b == 0 else __gcd(b, a % b)
	

def __lcm(a, b):
	return a * b / __gcd(a, b)


def __fact(n):
	return 1 if n == 1 else n * __fact(n - 1)


def __mex(a):
	mex = 0
	a.sort()
	for x in a:
		if x <= mex:
			mex += 1
		else:
			break
	return mex

def __dist(x1, y1, x2, y2):
	return (x1 - x2) ** 2 + (y1 - y2) ** 2

def __getprimes(n):
    isprime = [True for i in range(n + 1)]
    primes = []
     
    for i in range(2, n + 1):
        if isprime[i]:
            for j in range(i * i, n + 1, i):
                isprime[j] = False
    for i in range(2, n + 1):
        if isprime[i]:
            primes.append(i)
    return primes

def __modInverse(a, m):
    
    m0 = m
    y = 0
    x = 1
    if (m == 1):
        return 0
    
    while(a > 1):
    	q = a // m
    	t = m
    	m = a % m
    	a = t
    	t = y
    	y = x - q * y
    	x = t
    if (x < 0):
    	x = x + m0
    return x
    
    
    
def __isprime(n):
	if n < 2:
		return False
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True
	
def __cntprimediv(n):
	ret = 0
	x = n
	i = 2
	while i * i <= x:
		while n % i == 0:
			n //= i
			ret += 1
		i += 1
	if n > 1:
		ret += 1
	return ret
	
def __primefactors(n):
	ret = []
	x = n
	i = 2
	while i * i <= x:
		while n % i == 0:
			ret.append(i)
			n //= i
		i += 1
	if n > 1:
		ret.append(n)
	return ret
	

def __sumdigit(n):
	ret = 0
	while n > 0:
		ret += n % 10
		n //= 10
	return ret

def __zfunc(s):
	n = len(s)
	z = [0 for i in range(n)]
	l = 0
	r = 0
	for i in range(1, n):
		if r >= i:
			z[i] = min(z[i - l], r - i + 1)
		while z[i] + i < n and s[z[i]] == s[z[i] + i]:
			z[i] += 1
		if i + z[i] - 1 > r:
			l = i
			r = i + z[i] - 1
	return z
	
	
def __to(n, x):
	ret = ''
	while n > 0:
		q = n % x
		if q < 10:
			ret += str(q)
		else:
			ret += chr(q - 10 + ord('a'))
		n //= x
	return ret[::-1]
	
	
def solve(t):

	n = int(input())
	a = list(map(int, input().split()))
	needs = [True for i in range(n + 1)]
	v = []
	vv = []
	for i in range(n):
		if a[i] <= n and needs[a[i]]:
			needs[a[i]] = False 
		else:
			vv.append(a[i])
			
	for i in range(1, n + 1):
		if needs[i]:
			v.append(i)
	vv.sort()
	cnt = 0
	for i in range(len(v)):
		if v[i] * 2 < vv[i]:
			cnt += 1
		else:
			cnt = -1
			break
	print(cnt)
	
t = 1
t = int(input())


for i in range(t):
	solve(i + 1)