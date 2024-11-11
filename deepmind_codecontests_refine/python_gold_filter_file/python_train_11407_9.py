import sys
from collections import defaultdict as dd
from collections import deque
from fractions import Fraction as f
def eprint(*args):
    print(*args, file=sys.stderr)
pl=1
from math import *
import copy
#sys.setrecursionlimit(10**6)
if pl:
	input=sys.stdin.readline

def li():
	return [int(xxx) for xxx in input().split()]
def fi():
	return int(input())
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())	
 

d=[]		
from bisect import *		

from itertools import permutations 
from bisect import *
n,x=mi()
a=li()
d={}
for i in a:
	d[i]=0
for i in a:
	d[i]+=1
ans=1
#print(d)
for i in range(n):
	#print(a[i]^x)
	if a[i]^x==a[i]:
		ans+=(d[a[i]]-1)
	elif a[i]^x in d:
		ans+=d[a[i]^x]
print(ans//2)			
