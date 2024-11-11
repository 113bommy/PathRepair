import sys,math as mt
import heapq as hp
import collections as cc
import bisect as bi
import math as mt
import itertools as it
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
n,t=I()
ans=[]
for i in range(n):
	a,b=I()
	a-=t
	if a<0:
		a=a%b
	ans.append(a)
#print(ans)
print(ans.index(min(ans))+1)