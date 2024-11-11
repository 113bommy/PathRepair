#########			##	##     ##    	  ####  #####  ##     #  ##     #		##
	#			   # #	# #   # #		 #	  #	#	#  # #    #  # #    #	   # #
	#			  #  #	#  ###  #	    #		#	#  #  #   #  #  #   #	  #  #
	#			 #####	#	#	#	   #    ###	#	#  #   #  #  #   #  #    #####
	#			#    #	#		#	   #    # #	#	#  #	# #  #	  # #   #    #  
######### 	   #     # 	#		#		##### #	#####  #	 ##  #	   ##  #     #

"""

PPPPPPP       RRRRRRR		    OOOO	  VV        VV    EEEEEEEEEE
PPPPPPPP      RRRRRRRR         OOOOOO     VV       VV	  EE
PPPPPPPPP     RRRRRRRRR       OOOOOOOO    VV      VV	  EE
PPPPPPPP      RRRRRRRR        OOOOOOOO    VV     VV    	  EEEEEE
PPPPPPP       RRRRRRR         OOOOOOOO    VV    VV        EEEEEEE
PP  		  RRRR			  OOOOOOOO    VV   VV         EEEEEE
PP			  RR  RR          OOOOOOOO    VV  VV          EE
PP			  RR    RR         OOOOOO     VV VV           EE
PP			  RR      RR        OOOO      VVVV            EEEEEEEEEE

"""



"""
 Perfection is achieved not when there is nothing more to add, but rather when there is nothing more to take away.
"""
import sys
input = sys.stdin.readline
read = lambda: map(int, input().split())
# from bisect import bisect_left as lower_bound;
# from bisect import bisect_right as upper_bound;
# from math import ceil, factorial;

 
def ceil(x):
    if x != int(x):
        x = int(x) + 1
    return x
 
def factorial(x, m):
	val = 1
	while x>0:
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
def swaparr(arr, a,b):
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
 
## gcd function
def gcd(a,b):
    if b == 0:
        return a;
    return gcd(b, a % b);

## lcm function
def lcm(a, b):
	return (a * b) // math.gcd(a, b)
 
## nCr function efficient using Binomial Cofficient
def nCr(n, k): 
	if k > n:
		return 0
	if(k > n - k):
		k = n - k
	res = 1
	for i in range(k):
		res = res * (n - i)
		res = res / (i + 1)
	return int(res)
 
## upper bound function code -- such that e in a[:i] e < x;

 
## prime factorization
def primefs(n):
    ## if n == 1    ## calculating primes
    primes = {}
    while(n%2 == 0 and n > 0):
        primes[2] = primes.get(2, 0) + 1
        n = n//2
    for i in range(3, int(n**0.5)+2, 2):
        while(n%i == 0 and n > 0):
            primes[i] = primes.get(i, 0) + 1
            n = n//i
    if n > 2:
        primes[n] = primes.get(n, 0) + 1
    ## prime factoriazation of n is stored in dictionary
    ## primes and can be accesed. O(sqrt n)
    return primes
 
## MODULAR EXPONENTIATION FUNCTION
def power(x, y, p): 
    res = 1
    x = x % p  
    if (x == 0) : 
        return 0
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1      
        x = (x * x) % p 
    return res 
 
## DISJOINT SET UNINON FUNCTIONS
def swap(a,b):
    temp = a
    a = b
    b = temp
    return a,b;
 
# find function with path compression included (recursive)
# def find(x, link):
#     if link[x] == x:
#         return x
#     link[x] = find(link[x], link);
#     return link[x];
 
# find function with path compression (ITERATIVE)
def find(x, link):
    p = x;
    while( p != link[p]):
        p = link[p];
    
    while( x != p):
        nex = link[x];
        link[x] = p;
        x = nex;
    return p;
 
 
# the union function which makes union(x,y)
# of two nodes x and y
def union(x, y, link, size):
    x = find(x, link)
    y = find(y, link)
    if size[x] < size[y]:
        x,y = swap(x,y)
    if x != y:
        size[x] += size[y]
        link[y] = x
 
## returns an array of boolean if primes or not USING SIEVE OF ERATOSTHANES
def sieve(n): 
    prime = [True for i in range(n+1)] 
    prime[0], prime[1] = False, False
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    return prime

# Euler's Toitent Function phi
def phi(n) : 
  
    result = n 
    p = 2
    while(p * p<= n) : 
        if (n % p == 0) : 
            while (n % p == 0) : 
                n = n // p 
            result = result * (1.0 - (1.0 / (float) (p))) 
        p = p + 1
    if (n > 1) : 
        result = result * (1.0 - (1.0 / (float)(n))) 
   
    return (int)(result) 

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
def spf_sieve():
    spf[1] = 1;
    for i in range(2, MAXN):
        spf[i] = i;
    for i in range(4, MAXN, 2):
        spf[i] = 2;
    for i in range(3, ceil(MAXN ** 0.5), 2):
        if spf[i] == i:
            for j in range(i*i, MAXN, i):
                if spf[j] == j:
                    spf[j] = i;
    ## function for storing smallest prime factors (spf) in the array
 
################## un-comment below 2 lines when using factorization #################
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
    ## this function is useful for multiple queries only, o/w use
    ## primefs function above. complexity O(log n)

def factors(n):
	res = []
	for i in range(1, int(n ** 0.5) + 1):
		if n % i == 0:
			res.append(i)
			res.append(n // i)
	return list(set(res))
 
## taking integer array input
def int_array():
    return list(map(int, input().strip().split()));
 
def float_array():
    return list(map(float, input().strip().split()));
 
## taking string array input
def str_array():
    return input().strip().split();

def binary_search(low, high, w, h, n):
	while low < high:
		mid = low + (high - low) // 2
		# print(low, mid, high)
		if check(mid, w, h, n):
			high = mid
		else:
			low = mid + 1
	return low

## for checking any conditions
def check(time, m, assistants):
	summ = 0
	for p in assistants:
		time_needed_with_rest = p[0] * p[1] + p[2]
		time_needed_without_rest = p[0]
		baloons_can_be_inflated = p[1]
		summ += (time // time_needed_with_rest) * baloons_can_be_inflated
		ntime = time % time_needed_with_rest
		summ += min(ntime // time_needed_without_rest, baloons_can_be_inflated)
	return summ >= m

 
#defining a couple constants
MOD = int(1e9)+7;
CMOD = 998244353;
INF = float('inf'); NINF = -float('inf');
 
################### ---------------- TEMPLATE ENDS HERE ---------------- ###################
 
from itertools import permutations
import math
import bisect as bis
import random
import sys


def solve():
	a = input().rstrip()
	k = int(input())
	s = 0
	x = pow(2, len(a) * k, MOD) - 1 + MOD
	y = pow(2, len(a), MOD) - 1 + MOD
	## according to fermat's little theorem
	f = x * pow(y, MOD - 2, MOD) % MOD
	for i in range(len(a)):
		if a[i] == '5' or a[i] == '0':
			s = (s + pow(2, i, MOD)) % MOD
	# print(s, (2 ** (len(a) * k) - 1) // (2 ** len(a) - 1), len(a), k)
	print(s * f % MOD)
if __name__ == '__main__':
	for _ in range(1):
		solve()
	# fin_time = datetime.now()
# 	print("Execution time (for loop): ", (fin_time-init_time))
