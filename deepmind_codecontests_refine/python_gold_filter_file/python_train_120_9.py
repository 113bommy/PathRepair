import sys
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
from bisect import bisect_right
from bisect import bisect_left
from sys import stdin,stdout
from collections import defaultdict

inp=lambda : int(stdin.readline())
sip=lambda : input()
mulip =lambda : map(int,input().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
arr2d= lambda x: [[int(j) for j in input().split()] for i in range(x)]
odds = lambda l: len(list(filter(lambda x: x%2!=0, l)))
evens = lambda l: len(list(filter(lambda x: x%2==0, l)))
mod = pow(10,9)+7
#-------------------------------------------------------
for _ in range(inp()):
	a,b,c = mulip()
	m1 = min(b//2,a)*3 + min(b-2*min(b//2,a),c//2)*3 
	m2 = min(c//2,b)*3 + min((b-min(c//2,b))//2,a)*3 
	print(max(m1,m2)) 

