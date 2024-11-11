# from debug import debug
import sys; input = sys.stdin.readline
from collections import Counter
t = int(input())
for _ in range(t):
	n = int(input())
	lis = []
	c = Counter(dict())
	for _ in range(n):
		a = input().strip()
		c.update(a)
	g = 0
	for i in c:
		if c[i]%n: g = 1; break
	if g: print("NO")
	else: print("YES")