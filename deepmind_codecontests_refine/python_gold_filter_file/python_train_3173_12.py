n, k = (int(x) for x in input().split())
a = [int(x) for x in input().split()]
l = min(a)
h = max(a)
if h - l > k:
	print('NO')
	exit()
print('YES')
for x in a:
	for i in range(x):
		print(1 + i % k, end = ' ')
	print()