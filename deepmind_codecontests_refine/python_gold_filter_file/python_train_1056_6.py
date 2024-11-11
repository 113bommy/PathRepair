
from math import *
from itertools import *



n=int(input())
s=input()
s=s[::-1]

# print(max(0, s.count('+')-s.count('-') ))


tot=0

for i in range(105):
	now=i

	flg=0

	for j in s:
		if(j=='-'):
			now+=1
		else:
			now-=1
		if(now<0):
			flg=1
			break

	if(flg==0):
		tot=i
		break
print(tot)
