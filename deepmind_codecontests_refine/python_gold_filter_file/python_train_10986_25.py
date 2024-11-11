'''input
1
2
'''
n = int(input())
h = list(map(int, input().split()))
m = 0
for x in range(n):
	i, j = x, x
	while i > 0:
		if h[i-1] <= h[i]:
			i -= 1
		else:
			break
	while j < n-1:
		if h[j+1] <= h[j]:
			j += 1
		else:
			break
	m = max(m, j-i)
print(m+1)