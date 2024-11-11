import math
from decimal import Decimal
import heapq
import copy
import heapq
from collections import deque
from collections import defaultdict
def na():
	n = int(input())
	b = [int(x) for x in input().split()]
	return n,b
 
	
def nab():
	n = int(input())
	b = [int(x) for x in input().split()]
	c = [int(x) for x in input().split()]
	return n,b,c
 
		
def dv():
	n, m = map(int, input().split())
	return n,m
 
 
def da():
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	return n,m, a 
 
 
def dva():
	
	n, m = map(int, input().split())
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	return n,m,b
 
def prost(x):
	d = math.sqrt(x)
	d = int(d) + 1
	for i in range(2, d):
		if x % i == 0:
			return False
	return True


def eratosthenes(n): 
	sieve = list(range(n + 1))
	for i in sieve:
		if i > 1:
			for j in range(i + i, len(sieve), i):
				sieve[j] = 0
	return sorted(set(sieve))
 
 
def lol(lst,k):
	k=k%len(lst)
	ret=[0]*len(lst)
	for i in range(len(lst)):
		if i+k<len(lst) and i+k>=0:
			ret[i]=lst[i+k]
		if i+k>=len(lst):
			ret[i]=lst[i+k-len(lst)]
		if i+k<0:
			ret[i]=lst[i+k+len(lst)]
	return(ret)


def nm():
	n = int(input())
	b = [int(x) for x in input().split()]
	m = int(input())
	c = [int(x) for x in input().split()]
	return n,b,m,c
 
 
def dvs():
	n = int(input())
	m = int(input())
	return n, m 
 

n = int(input())
a = list(map(int, input().split()))
dp = [0] * (6 * 100000)
for i in range(n):
	dp[a[i] - i] += a[i]
print(max(dp))
