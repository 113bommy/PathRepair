n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
for i in range(n):
	a[i] = [a[i], i]
a.sort()
ans = []
for i in range(k):
	if all(x == a[0] for x in a):
		break
	l = 0
	r = n - 1
	for i in range(n - 1):
		if a[i][0] < a[i + 1][0]:
			l = i
			break
	for i in range(n - 1, 0, -1):
		if a[i - 1][0] < a[i][0]:
			r = i
			break
	if a[l][0] + 1 >= a[r][0]:
		break
	ans.append(str(a[r][1] + 1) + ' ' + str(a[l][1] + 1))
	a[l][0] += 1
	a[r][0] -= 1
print(max(x[0] for x in a) - min(x[0] for x in a), len(ans))
print('\n'.join(ans))
