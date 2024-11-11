import sys
from collections import defaultdict as dd
from collections import deque
from fractions import Fraction as f
def eprint(*args):
    print(*args, file=sys.stderr)
zz=1
from math import *
import copy
#sys.setrecursionlimit(10**6)
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')
def li():
	return [int(x) for x in input().split()]
def fi():
	return int(input())
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())	
def gh():
	sys.stdout.flush()
def bo(i):
	return ord(i)-ord('a')
from copy import *
from bisect import *	

from itertools import permutations 


def can(mid):
	c=0
	for i in range(n):
		c+=max(0,a[i]-i//mid)

	return c>=m	
n,m=mi()
a=li()
if sum(a)<m:
	print(-1)
	exit(0)
a.sort(reverse=True)
l=1
r=10**15
while l<=r:
	mid=(l+r)//2
	if can(mid):
		ans=mid
		r=mid-1
	else:
		l=mid+1
print(ans)		

