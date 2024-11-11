import math as ma
import sys
from sys import exit
from decimal import Decimal as dec
from itertools import permutations

def li():
	return list(map(int , input().split()))

def num():
	return map(int , input().split())

def nu():
	return int(input())

def find_gcd(x , y):
	while (y):
		x , y = y , x % y
	return x

n=nu()
a=li()
b=li()
z=[]
for i in range(n):
	z.append((a[i]+b[i],i))
z.sort()
fl=True
x=[]
cc=0
xp=0
mp={}
np=[]
for i in range(n):
	if(a[i]>i):
		fl=False
	if(b[i]>(n-i-1)):
		fl=False
	if((n-a[i]-b[i])<=0):
		fl=False

if(fl==False):
	print("NO")
else:
	zz=[0]*n
	for i in range(n):
		zz[i]=(n-a[i]-b[i])
	for i in range(n):
		xl = 0
		xr = 0
		for j in range(i + 1 , n):
			if (zz[j] > zz[i]):
				xr += 1
		for j in range(i - 1 , -1 , -1):
			if (zz[j] > zz[i]):
				xl += 1
		if (xl != a[i] or xr != b[i]):
			fl = False
			break
	if (fl == True):
		print("YES")
		print(*zz)
	else:
		print("NO")
