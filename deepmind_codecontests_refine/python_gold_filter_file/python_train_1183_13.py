n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
if n<k:
	print(-1)
	exit()
print(a[n-k],0)