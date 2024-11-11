import math
for _ in range(int(input())) :
	a,b,c,d,k= map(int,input().split())
	if math.ceil(a/c) + math.ceil(b/d) <= k :
		print(math.ceil(a/c),math.ceil(b/d))
	else :
		print(-1)