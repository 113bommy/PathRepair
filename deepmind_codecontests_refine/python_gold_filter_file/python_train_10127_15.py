# Anuneet Anand

import sys
input = sys.stdin.readline
# #sys.setrecursionlimit(10**5)

T = int(input())
 
while T:
	n,q = map(int,input().split())
	A = list(map(int,input().split()))

	s = 0
	f = True
	for i in range(n-1):
		if f:
			if A[i]>A[i+1]:
				s += A[i]
				f = False
		else:
			if A[i]<A[i+1]:
				s -= A[i]
				f = True

	if f:
		s+=A[n-1]

	print(s)
	T = T - 1


 
 
 
 




