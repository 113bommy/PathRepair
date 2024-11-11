t = int(input())
for i in range(t):
	n = int(input())
	a = input()
	b = input()
	j = n-1
	while(a[j] ==b[j]):
		j -= 1
		if j == -1:
			break
	if j == -1:
		print(0)
		continue
	if j == 0:
		print(1,1)
		continue
	res = []
	k= 0
	while(j>0):
		if b[j] == a[k]:
			res.append(1)
			res.append(j+1)
		else:
			res.append(j+1)
		k += 1
		j -= 1
		while(b[j] != a[k] and j >0):
			j -= 1
			k += 1
		if j >0:
			res.append(j+1)
	if b[j] == a[k]:
		res.append(1)
	print(len(res),*res)
