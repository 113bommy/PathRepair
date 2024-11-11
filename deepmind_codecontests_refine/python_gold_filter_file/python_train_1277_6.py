import math, sys
from collections import defaultdict, Counter, deque
from functools import reduce

INF = float('inf')
MOD = int(1e9) + 7
 
def gcd(a, b):
	while b:
		a, b = b, a%b
	return a
 
def isPrime(n):
	if (n <= 1): 
		return False
	i = 2
	while i ** 2 <= n:
		if n % i == 0:
			return False
		i += 1
	return True
 
def primeFactors(n):
	factors = defaultdict(int)
	i = 2
	while i ** 2 <= n:
		while n % i == 0:
			factors[i] += 1
			n //= i 
		i += 1
	if n > 1:
		factors[n] += 1 
	return factors

def factors(n):    
	return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

def vars():
	return map(int, input().split())
 
def array():
	return list(map(int, input().split()))

def main():
	n = int(input())
	arr = array()

	maxi = max(arr)

	ans = []
	
	while arr:
		curr, val = 0, None
		for num in arr:
			g = gcd(maxi, num)
			if g > curr:
				curr = g 
				val = num 

		maxi = curr

		ans.append(val)
		arr.remove(val)

	print(*ans)


if __name__ == "__main__":
	t = 1
	t = int(input())
	for _ in range(t):
		main()
