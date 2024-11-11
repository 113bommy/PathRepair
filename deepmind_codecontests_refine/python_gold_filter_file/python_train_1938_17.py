from math import sqrt
r, d = map(int, input().split())
n = int(input())
ans = 0
for i in range(n):
	x, y, ri = map(int,input().split())
	n_dist = sqrt(x**2+y**2) - ri
	f_dist = n_dist + 2*ri
	if n_dist>=r-d and f_dist<=r:
		ans+=1
print(ans)