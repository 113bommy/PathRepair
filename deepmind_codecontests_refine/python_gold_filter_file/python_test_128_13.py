import sys
import math as mt
import collections as cc

I = lambda : list(map(int,input().split()))
mod = 10**9+7
def ch(temp):
	tans = 0
	for i in range(len(temp)-k-1,-1,-k):
		tans += 2*abs(temp[i])
	return tans 

for tc in range(int(input())):
	n, = I()
	if n%2==0:
		print(n//2,n//2-1,1)
	else:
		m = (n-1)//2

		if m%2==0:
			print(m-1,m+1,1)
		else:
			print(m-2,m+2,1)
