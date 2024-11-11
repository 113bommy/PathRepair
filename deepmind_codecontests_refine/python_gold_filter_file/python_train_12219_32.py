#####--------------Template Begin-------------------####
import math
import sys
import string
#input = sys.stdin.readline
def ri(): #Regular input
	return input()
def ii(): #integer input
	return int(input())
def li(): #list input
	return input().split()
def mi(): #map input
	return list(map(int, input().split()))
#####---------------Template Ends-------------------######
n=ii()
a=mi()

c=[a[i] for i in range(0, n, 3)]
b=[a[i] for i in range(1, n, 3)]
back=[a[i] for i in range(2, n, 3)]

if sum(c)>sum(b) and sum(c)>sum(back):
	print("chest")
elif sum(b)>sum(c) and sum(b)>sum(back):
	print("biceps")
else:
	print("back")
