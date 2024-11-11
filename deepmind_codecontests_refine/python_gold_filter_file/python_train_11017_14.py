n = int(input())
a = list(map(int, input().split()))

b = 0
by = 0
flg = 0
for i,j in enumerate(a):
	if abs(j) > abs(b):
		b = j
		by = i+1
		if j > 0:
			flg = 1
		else:
			flg = 0
ans = []
if flg == 1:
	x = min(a)
	if x < 0:
		for i in range(n):
			if a[i] != b:
				a[i] += b
				ans.append([by,i+1])
	for i in range(1,n):
		a[i] += a[i-1]
		ans.append([i,i+1])
else:
	x = max(a)
	if x > 0:
		for i in range(n-1,-1,-1):
			if a[i] != b:
				a[i] += b
				ans.append([by,i+1])
	for i in range(n-2,-1,-1):
		a[i] += a[i+1]
		ans.append([i+2,i+1])
print (len(ans))
for i in ans:
	print (*i)
