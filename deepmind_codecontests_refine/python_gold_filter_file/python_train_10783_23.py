n, m = map(int,input().split())
def valid(k, n):
	cont_sum = k * (k+1) // 2
	return n <= cont_sum
	
if n > m:
	MAX = 2000000000
	left, right = 1, MAX
	desire = n-m
	while left < right:
		mid = (left + right) // 2
		if valid(mid, desire):
			right = mid
		else:
			left = mid+1
	print(left+m)
			
else:
	print(n)
