t = int(input())

for i in range(t):
	a = [int(x) for x in input().split()]
	p = a[1]
	q = a[2]
	r = a[3]

	while (p+q <=r):
		r = int((r+q)/2)
	print(p,q,r)
	# print("a")