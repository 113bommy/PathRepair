from sys import stdin,stdout,setrecursionlimit
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush,nlargest
from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm , accumulate
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
import copy
import time
setrecursionlimit(10**9)
starttime = time.time()
mod = int(pow(10, 9) + 7)
mod2 = 998244353
# from sys import stdin
# input = stdin.readline
#def data(): return sys.stdin.readline().strip()
def data(): return input()
def num():return int(input())
def L(): return list(sp())
def LF(): return list(spf())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def spf(): return map(int, input.readline().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
def pmat(A):
    for ele in A:
        print(*ele,end="\n")
def pmat2(A):
    for ele in A:
        for j in ele:
            print(j,end='')
        print()
def iseven(n):
    return n%2==0

def seive(r):
    prime=[1 for i in range(r+1)]
    prime[0]=0
    prime[1]=0
    for i in range(r+1):
        if(prime[i]):
            for j in range(2*i,r+1,i):
                prime[j]=0
    return prime
#solution
#ACPC 
#remeber cut ribbon problem
# set data structures faster than binary search sometimes
#bipartite match dfs
#think in problems with recursive manner.
def isprime(x):
	if x==2:return True
	elif x%2==0:return False
	sq=int(sqrt(x))+1
	for i in range(3,sq,2):
		if x%i==0:
			return False
	return True
n=int(input());m=n
while not isprime(m):m+=1
print(m)
print(1,n)
for i in range(n-1):
	print(i+1,i+2)
for i in range(m-n):
	print(i+1,i+1+n//2)





		
endtime = time.time()
#print(f"Runtime of the program is {endtime - starttime}")