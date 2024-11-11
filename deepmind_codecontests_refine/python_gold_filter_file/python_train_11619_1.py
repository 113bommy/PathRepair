n,m = map(int,input().split())
a = list(map(int,input().split()))

for _ in range(m):
	l,r,x =  map(int,input().split())

	
	t = a[x-1]
	lcount = 0
	gcount = 0
	for i in range(l-1,r):

		if a[i] < t and i > x-1:
			
			lcount += 1
		if a[i] > t and i < x-1:
			gcount -= 1
	
	if (lcount + gcount) != 0:
		print("No")
	else:
		print("Yes")