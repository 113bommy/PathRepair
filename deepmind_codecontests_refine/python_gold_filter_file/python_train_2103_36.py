import math
t = int(input())
while t > 0:
	t -= 1
	a,b,c,d,k = map(int,input().split())

	a1 = math.ceil(a/c)
	a2 = math.ceil(b/d)

	if a1 + a2 > k:
		print(-1)
	else:
		print(a1,a2)
