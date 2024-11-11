import sys
from collections import defaultdict as dd
from collections import deque
from fractions import Fraction as f

from itertools import permutations 

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
def lol(p):
	h=bin(p)[2:]
	h="0"*(60-len(h))+h
	print(h)
n=fi()
a=li()
ans=0
c=[0 for i in range(31)]
for i in range(n):
	for j in range(30):
		if a[i]&(1<<j):
			c[j]+=1
			
for i in range(n):
	x=0
	for j in range(30):
		if c[j]>0:
			c[j]-=1
			x|=(1<<j)
	
	ans+=x**2
print(ans)			
