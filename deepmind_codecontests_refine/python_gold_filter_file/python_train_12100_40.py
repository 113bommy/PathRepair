def zip_sorted(a,b): return zip(*sorted(zip(a,b)))[0],zip(*sorted(zip(a,b)))[1]
def gcd(a,b): return math.gcd(a,b)
def lcm(a,b): return ((a*b)//math.gcd(a,b))
def ncr(n,r): return math.comb(n,r)
def npr(n,r): return (math.factorial(n)//math.factorial(n-r))
def decimal_to_binary(n): return bin(n).replace("0b", "")
def binary_to_decimal(s): return int(s,2)

import sys, os.path
import math
from collections import defaultdict,deque

input = sys.stdin.readline

I = lambda : list(map(int,input().split()))
S = lambda : list(map(str,input()))

def main():

	t,=I()
	for t1 in range(t):
		x,y,a,b = I()
		num = (y-x) 
		dem = (a+b)
		if num%dem==0:
			print(num//dem)
		else:
			print(-1)

main()
