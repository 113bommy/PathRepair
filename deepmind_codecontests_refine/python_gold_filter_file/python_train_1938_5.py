import math
r, d = [ int(i) for i in input().strip().split(' ')]
n = int(input().strip())
ans = 0
for i in range(n):
	x, y, ri = [ int(i) for i in input().strip().split(' ')]
	l = math.sqrt(x*x+y*y)
	if r-d<=l-ri and l+ri<=r:
		ans = ans + 1
print(ans)	