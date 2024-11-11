import sys
from itertools import combinations as cb
input = sys.stdin.readline
h = {'S' : 1, 'E' : 2, 'T' : 3} 

n, k = map(int,input().split())
S = set(tuple(map(h.get, input().rstrip())) for _ in range(n))

ans = 0
for a, b in cb(S, 2):
	c = []
	for i in range(k):
		if a[i] == b[i]:
			c.append(a[i])
		else:
			t = 6 - a[i] - b[i]
			c.append(t)
	if tuple(c) in S:
		ans += 1
			
print(ans//3)