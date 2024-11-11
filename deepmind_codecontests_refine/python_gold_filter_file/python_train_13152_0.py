from sys import stdin,stdout
from math import ceil,floor,sqrt
from collections import deque,Counter
inp = stdin.readline
out = stdout.write

n,x,y,z=map(int,inp().strip().split())
a = [0]+[-5000]*4001
for i in range(1,n+1):
	a[i]=max(a[i-x],a[i-y],a[i-z])+1
out(str(a[n]))