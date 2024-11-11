n = int(input())
v = [int(i) for i in input().split()]
ans = 0
for i in range(n):
	if i != 0 and i != n-1 and (v[i-1] > v[i] or v[i+1] >= v[i]):
		continue
	tmp = 1
	for j in range(i-1, -1, -1):
		if v[j] <= v[j+1]:
			tmp += 1
		else:
			break
	for j in range(i+1, n, 1):
		if v[j] <= v[j-1]:
			tmp += 1
		else:
			break
	ans = max(ans, tmp)
print(ans)

