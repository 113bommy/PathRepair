n ,k = [int(x) for x in input().strip().split()]
l = list(range(1,n+1))
if k==n-1:
	print(" ".join([str(x) for x in l[::-1]]))
elif k == 0:
	print(" ".join([str(x) for x in l]))
else:
	l = l[:n-k-1]+l[n-k-1:][::-1]

	print(" ".join([str(x) for x in l]))