import sys
input = sys.stdin.readline


def factorial(x, m):
	val = 1
	while x > 0:
		val = (val * x) % m
		x -= 1
	return val


def fact(x):
	val = 1
	while x > 0:
		val *= x
		x -= 1
	return val


# swap_array function
def swaparr(arr, a, b):
	temp = arr[a]
	arr[a] = arr[b]
	arr[b] = temp


def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def nCr(n, k):
	if k > n:
		return 0
	if (k > n - k):
		k = n - k
	res = 1
	for i in range(k):
		res = res * (n - i)
		res = res / (i + 1)
	return int(res)

## prime factorization
def primefs(n):
	primes = {}
	while (n % 2 == 0 and n > 0):
		primes[2] = primes.get(2, 0) + 1
		n = n // 2
	for i in range(3, int(n ** 0.5) + 2, 2):
		while (n % i == 0 and n > 0):
			primes[i] = primes.get(i, 0) + 1
			n = n // i
	if n > 2:
		primes[n] = primes.get(n, 0) + 1
	## prime factoriazation of n is stored in dictionary
	## primes and can be accesed. O(sqrt n)
	return primes


## MODULAR EXPONENTIATION FUNCTION
def power(x, y, p):
	res = 1
	x = x % p
	if (x == 0):
		return 0
	while (y > 0):
		if ((y & 1) == 1):
			res = (res * x) % p
		y = y >> 1
		x = (x * x) % p
	return res

## returns an array of boolean if primes or not USING SIEVE OF ERATOSTHANES
def sieve(n):
	prime = [True for i in range(n + 1)]
	prime[0], prime[1] = False, False
	p = 2
	while (p * p <= n):
		if (prime[p] == True):
			for i in range(p * p, n + 1, p):
				prime[i] = False
		p += 1
	return prime

def is_prime(n):
	if n == 0:
		return False
	if n == 1:
		return True
	for i in range(2, int(n ** (1 / 2)) + 1):
		if not n % i:
			return False

	return True


#### PRIME FACTORIZATION IN O(log n) using Sieve ####
MAXN = int(1e5 + 5)
import math
def spf_sieve():
	spf[1] = 1
	for i in range(2, MAXN):
		spf[i] = i
	for i in range(4, MAXN, 2):
		spf[i] = 2
	for i in range(3, math.ceil(MAXN ** 0.5), 2):
		if spf[i] == i:
			for j in range(i * i, MAXN, i):
				if spf[j] == j:
					spf[j] = i

spf = [0 for i in range(MAXN)]

# spf_sieve();
def factoriazation(x):
	res = []
	for i in range(2, int(x ** 0.5) + 1):
		while x % i == 0:
			res.append(i)
			x //= i
	if x != 1:
		res.append(x)
	return res

def factors(n):
	res = []
	for i in range(1, int(n ** 0.5) + 1):
		if n % i == 0:
			res.append(i)
			res.append(n // i)
	return list(set(res))

def int_array():
	return list(map(int, input().strip().split()))

def float_array():
	return list(map(float, input().strip().split()))


def str_array():
	return input().strip().split()

# defining a couple constants
MOD = int(1e9) + 7
CMOD = 998244353
INF = float('inf')
NINF = -float('inf')

################### ---------------- TEMPLATE ENDS HERE ---------------- ###################

from itertools import permutations
import math
from bisect import bisect_left
#for _ in range(int(input())):
from collections import Counter
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
import heapq
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
# n = int(input())
# ls = list(map(int, input().split()))
# n, k = map(int, input().split())
# n =int(input())
# arr=[(i,x) for i,x in enum]
# arr.sort(key=lambda x:x[0])
# e=list(map(int, input().split()))
from collections import Counter
# print("\n".join(ls))
# print(os.path.commonprefix(ls[0:2]))
# n=int(input())
from bisect import bisect_right
# d=sorted(d,key=lambda x:(len(d[x]),-x))  d=dictionary     d={x:set() for x in arr}
# n=int(input())
# n,m,k= map(int, input().split())
import heapq
# for _ in range(int(input())):
# n,k=map(int, input().split())
#for _ in range(int(input())):
#n = int(input())
# code here ;))

#n,k=map(int, input().split())
#arr = list(map(int, input().split()))
#ls= list(map(int, input().split()))
import math
#n = int(input())
#n,k=map(int, input().split())
#for _ in range(int(input())):
#n = int(input())
#n,l=map(int,input().split())
#for _ in range(int(input())):
def divisors_seive(n):
	divisors=[10**6+6]
	for i in range(1,n+1):
		for j in range(i,n+1):
			divisors[j]+=1

def dfs(s,par,vis,rank):
	vis[s]=1
	global res
	res=1
	rank[s]=1
	f=0
	for i in g[s]:
		f=1
		if par==i:
			continue
		rank[s]+=dfs(i,s)
	#if rank[s]%2==0 and s!=1:
		#res+=1
	#if f==0:
	return res
#n=int(input())
#n=int(input())
import bisect
from collections import deque
n,m,k=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
d=deque([])
ans=0
for i in arr:
	if len(d)>0 and d[0]<i-m+1:
		d.popleft()
	if len(d)<k-1:
		d.append(i)
	else:
		ans+=1
print(ans)
