a,b,c,d=list(map(int,input().split()))
x=[a,b,c]
x.sort(reverse=True)
if x[0]-x[1]>=d and x[1]-x[2]>=d:
	print(0)
else:
	if x[0]-x[1]<d and x[1]-x[2]<d:
		print(2*d-(x[0]-x[2]))
	else:
		print(d-x[0]+x[1]) if x[0]-x[1]<d else print(d-x[1]+x[2])