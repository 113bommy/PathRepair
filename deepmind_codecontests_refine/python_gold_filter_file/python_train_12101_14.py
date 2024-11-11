def frst_indx(n,k):
	begin, end = 0, 0
	for i in range(n*(n-1)):
		if begin<=k<=end:
			break
		else: begin, end=end+1, end+i
	return i-1

t=int(input())

for _ in range(t):
	n,k = map(int, input().split())
	fi = frst_indx(n,k)
	si = (k-(1+(fi-1)*fi//2))
	print(''.join(['a', 'b'][i==fi or i==si] for i in range(n))[::-1])
