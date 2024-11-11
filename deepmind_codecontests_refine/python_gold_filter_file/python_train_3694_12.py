from functools import reduce
from operator import *
from math import *
from sys import *
from string import *
setrecursionlimit(10**7)
RI=lambda: list(map(int,input().split()))
RS=lambda: input().rstrip().split()
#################################################
def isPalindrome(a):
	return a==a[::-1]
x=RS()[0]
for i in range(len(x)+1):
	a,b= x[:i], x[i:]
	for c in ascii_lowercase:
		if(isPalindrome(a+c+b)):
			print(a+c+b)
			exit(0)
print("NA")
