# DEFINING SOME GOOD STUFF
from math import *
import threading
import sys
mod = 10**9 + 7
 
# _______________________________________________________________#
 
def npr(n,r):
	return factorial(n)//factorial(n-r) if n >= r else 0
 
 
def lower_bound(li, num):
	answer = -1
	start = 0
	end = len(li) - 1
 
	while (start <= end):
		middle = (end + start) // 2
		if li[middle] >= num:
			answer = middle
			end = middle - 1
		else:
			start = middle + 1
	return answer  # index where x is not less than num
 
 
def upper_bound(li, num):
	answer = -1
	start = 0
	end = len(li) - 1
 
	while (start <= end):
		middle = (end + start) // 2
 
		if li[middle] <= num:
			answer = middle
			start = middle + 1
 
		else:
			end = middle - 1
	return answer  # index where x is not greater than num
 
 
def abs(x):
	return x if x >= 0 else -x
 
 
def binary_search(li, val, lb, ub):
	ans = -1
	while (lb <= ub):
		mid = (lb + ub) // 2
		# print(mid, li[mid])
		if li[mid] > val:
			ub = mid - 1
		elif val > li[mid]:	
			lb = mid + 1
		else:
			ans = mid # return index
			break
	return ans
 
 
def kadane(x):  # maximum sum contiguous subarray
	sum_so_far = 0
	current_sum = 0
	for i in x:
		current_sum += i
		if current_sum < 0:
			current_sum = 0
		else:
			sum_so_far = max(sum_so_far, current_sum)
	return sum_so_far
 
 
def pref(li):
	pref_sum = [0]
	for i in li:
		pref_sum.append(pref_sum[-1] + i)
	return pref_sum
 
 
def graph(n, m):
	adj = dict()
	for i in range(1, n + 1):
		adj.setdefault(i, 0)
	for i in range(m):
		a, b = map(int, input().split())
		adj[a] += 1
		adj[b] += 1
	return adj
 
 
def SieveOfEratosthenes(n):
	prime = [True for i in range(n+1)]
	p = 2
	li = []
	while (p * p <= n):
		if (prime[p] == True):
			for i in range(p * p, n+1, p):
				prime[i] = False
		p += 1
 
	for p in range(2, len(prime)):
		if prime[p]:
			li.append(p)
	return li
 
def primefactors(n):
	factors = []
	while(n%2 == 0):
		factors.append(2)
		n //= 2
	for i in range(3, int(sqrt(n))+1, 2): #only odd factors left
		while n%i == 0:
			factors.append(i)
			n //= i
	if n>2: # incase of prime
		factors.append(n)
	return factors
 
def prod(li):
	ans = 1
	for i in li:
		ans *= i
	return ans
# _______________________________________________________________#
 
 
 
sys.setrecursionlimit(300000)
# threading.stack_size(10**5)  # remember it cause mle
#def main():
for _ in range(int(input()) if True else 1):
	#n = int(input())
	n,w = map(int, input().split())
	#s = list(input())
	#s = [int(x) for x in s]
	a = list(map(int, input().split()))
	#b = list(map(int,input().split()))
	#s = input()
	#c = list(map(int,input().split()))
	# adj = graph(n,m)
	b = []
	for i in range(n):
		b.append((a[i], i+1))
	b.sort()
	weight = 0
	ans = []
	f = 0
	for i in range(n):
		weight += b[i][0]
		
		ans.append(b[i][1])
		if weight > w:
			if b[i][0] >= (w+1)//2 and b[i][0] <= w:
				ans = [b[i][1]]
				f = 1
			break
		elif weight >= (w+1)//2:
			f = 1
			break
	ans.sort()
	if f:
		print(len(ans))
		print(*ans)
	else:
		print(-1)

	

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
	
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
'''		
t = threading.Thread(target=main)
t.start()
t.join()
'''