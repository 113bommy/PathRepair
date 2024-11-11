t = int(input())
for tt in range(t):
	n = int(input())
	a = input().split()
	a.sort()
	res = abs(int(a[n-1]) - int(a[0]))
	for i in range(n):
		for j in range(i+1,n):
			res = min(res,abs(int(a[j])-int(a[i])))
	print(res)
