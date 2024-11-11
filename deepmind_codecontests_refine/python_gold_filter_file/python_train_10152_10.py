from sys import stdin,stdout
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as dd,Counter as C,deque
from math import ceil,gcd,sqrt,factorial
from itertools import permutations 


def bisector_left(arr,x):
	ind=-1
	s=0
	e=len(arr)-1
	while s<=e:
		m=s+(e-s)//2
		if arr[m]<x:
			s=m+1
		else:
			e=m-1
			ind=m
	return ind

def bisector_right(arr,x):
	ind=-1
	s=0
	e=len(arr)-1
	while s<=e:
		m=s+(e-s)//2
		if arr[m]<=x:
			s=m+1
			ind=m
		else:
			e=m-1
	return ind


l,r,k = mp()
v=[]
for i in range(65):
	v.append(k**i)
x = bisector_left(v,l)
y = bisector_right(v,r)
# print(x,y)
if x<=y:
	for i in range(x,y+1):
		print(v[i],end = ' ')
else:
	print(-1)

