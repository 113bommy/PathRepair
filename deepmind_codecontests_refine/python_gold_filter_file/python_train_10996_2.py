import sys
input=sys.stdin.buffer.readline
import os
from math import*

def func(x):
	if n>=x:
		val=(x-1)//2
	else:
		val=(n+n+1-x)//2
	return max(0,val)


n=int(input())
x=[0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999]
s=n+n-1
if x[len(str(s))]==s:
	print("1")
else:
	ans=0
	k=x[len(str(s))]//10
	for i in range(0,10):
		if (i*(k+1))+k<=s:
			ans+=func(i*(k+1)+k)
		else:
			break
	print(ans)