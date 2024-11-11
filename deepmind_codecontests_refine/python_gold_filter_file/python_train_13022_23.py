q, n = map(int, input().split())
arr = [1]*n
for i in range(q):
	l, r = map(int, input().split())
	for j in range(l-1, r):
		arr[j] = 0

if sum(arr) == 0:
	print(0)
else:
	print(sum(arr))
	for i in range(n):
		if arr[i] == 1:
			print(i+1, end = ' ')