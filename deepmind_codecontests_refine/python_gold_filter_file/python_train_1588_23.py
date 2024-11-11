import sys
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
 

t=fi()


while t>0:
	t-=1
	n=fi()
	#print((pi/180)*(360/(4*n)))
	s=1/(2*tan((pi/180)*(360/(4*n))))
	print(2*s)


