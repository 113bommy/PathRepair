from bisect import bisect_left
from collections import defaultdict as D

MAX = 99999999999

for _ in range(int(input())):
	s = input()
	
	n,k = map(int,input().split())
	
	a = list( map( int, input().split() ) )
	t = list( map( int, input().split() ) )
	
	d=D(int)
	for i in range(k):
		a[i] -=1
		d[a[i]] = t[i]
	
	ans=[MAX for i in range(n)]
	r = MAX
	for i in range(n):	
		if d[i] == 0: d[i] = MAX
		r = min(r, d[i])
		ans[i] = min(ans[i], r)    	
		r+=1
	
	for i in range(n-1,-1,-1):	
		if d[i] == 0: d[i] = MAX
		r = min(r, d[i])
		ans[i] = min(ans[i], r)    	
		r+=1
	print(*ans)
