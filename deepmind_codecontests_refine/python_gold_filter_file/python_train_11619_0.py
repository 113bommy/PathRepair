m, n = map(int, input().split())
b = list(map(int, input().split()))
for i in range(n):
	l, r, x = map(int, input().split())
	cnt = 0
	for j in range(l-1, r):
		if b[j] < b[x-1]:
			cnt += 1
	if cnt == x - l:
		print("Yes")
	else:
		print("No")
		