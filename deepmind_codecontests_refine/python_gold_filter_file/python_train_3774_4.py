#                                               |
#   _` |  __ \    _` |   __|   _ \   __ \    _` |   _` |
#  (   |  |   |  (   |  (     (   |  |   |  (   |  (   |
# \__,_| _|  _| \__,_| \___| \___/  _|  _| \__,_| \__,_|

import sys
import math
import operator as op
from functools import reduce

def read_line():
	return sys.stdin.readline()[:-1]
 
def read_int():
	return int(sys.stdin.readline())
	
def read_int_line():
	return [int(v) for v in sys.stdin.readline().split()]

def read_float_line():
	return [float(v) for v in sys.stdin.readline().split()]

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

def isSameforOne(a,b):
	cnt = 0
	for i in range(len(a)):
		if a[i]!=b[i]:
			cnt += 1
		if cnt>1:
			return False
	return True

t = read_int()
for i in range(t):
	n, m = read_int_line()
	st = []
	for i in range(n):
		a = read_line()
		st.append(a)

	s = []
	a = st[0]
	l = [chr(i) for i in range(97,123)]
	for i in range(m):
		for j in l:
			temp = a[:i]+j+a[i+1:]
			s.append(temp)
	# print(s)
	ans = "-1"
	for i in s:
		f = False
		for j in range(n):
			f = isSameforOne(i,st[j])
			if not f:
				break
		if f:
			ans = i
			break

	print(ans)



