import sys
from collections import defaultdict as dd
from collections import Counter as cc
from queue import Queue
import math
import itertools
try:
	sys.stdin = open('input.txt', 'r')
	sys.stdout = open('output.txt', 'w')
except:
	pass
input = lambda: sys.stdin.buffer.readline().rstrip()


for _ in range(int(input())):
	x,y=map(int,input().split())
	c1,c2,c3,c4,c5,c6=map(int,input().split())
	a1=min(c1,c6+c2)
	a2=min(c2,c1+c3)
	a3=min(c3,c4+c2)
	a4=min(c4,c3+c5)
	a5=min(c5,c4+c6)
	a6=min(c6,c5+c1)
	c1=a1
	c2=a2
	c3=a3
	c4=a4
	c5=a5
	c6=a6
	k=0
	if x>=0 and y>=0:
		r=min(x,y)
		k+=c1*r
		x-=r
		y-=r
	if x<=0 and y<=0:
		r=max(x,y)
		x-=r
		y-=r
		r*=-1
		k+=c4*r
	if y>=0:
		k+=c2*y
	else:
		y*=-1
		k+=c5*y
	if x>=0:
		k+=c6*x
	else:
		x*=-1
		k+=c3*x
	print(k)