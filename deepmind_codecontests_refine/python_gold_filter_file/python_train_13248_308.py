import sys
import math 
from decimal import *
def I(): return int(sys.stdin.readline())
def IL(): return list(map(int,sys.stdin.readline().strip().split()))
def ILS(): return list(map(str,sys.stdin.readline().strip().split()))

def solve():
	tt = I()
	for ii in range(tt):
		n  = I()
		if n== 1 : print(1)
		elif n == 2 : print(2)
		elif n%2 == 1 : print((n-1)//2 +1)
		else : print((n-2)//2 +2)
		pass
		

solve()