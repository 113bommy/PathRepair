n = int(input())
a = input()
b = input()
d1 = {}
d2 = {}
for i in range(n):
	if a[i] not in d1:
		d1[a[i]] = [1, [i+1]]
	else:
		d1[a[i]][0] += 1
		d1[a[i]][1].append(i+1)
for i in range(n):
	if b[i] not in d2:
		d2[b[i]] = [1, [i+1]]
	else:
		d2[b[i]][0] += 1
		d2[b[i]][1].append(i+1)
ans = 0
pairs = []
extras1 = []
extras2 = []
l1 = 0
l2 = 0
for i in d1.keys():
	if i != '?':
		if i in d2.keys():
			x = min(d1[i][0], d2[i][0])
			ans += x
			for j in range(x):
				u = d1[i][1].pop()
				v = d2[i][1].pop()
				pairs.append((u, v))
for i in d1.keys():
	if i != '?':
		while d1[i][1]:
			u = d1[i][1].pop()
			l1 += 1
			extras1.append(u)
for i in d2.keys():
	if i != '?':
		while d2[i][1]:
			u = d2[i][1].pop()
			l2 += 1
			extras2.append(u)
if '?' in d1.keys():
	x = min(d1['?'][0], l2)
	y = min(x, n-ans)
	ans += y
	for j in range(y):
		u = d1['?'][1].pop()
		v = extras2.pop()
		pairs.append((u, v))
	while d1['?'][1]:
			extras1.append(d1['?'][1][0])
			d1['?'][1].pop(0)
			l1 += 1
# print("extras1 = ", extras1)
# print("extras2 = ", extras2)
# print("l1 = ", l1)
if ans < n:
	if '?' in d2.keys():
		x = min(d2['?'][0], l1)
		y = min(x, n-ans)
		ans += y
		for j in range(y):
			u = d2['?'][1].pop()
			v = extras1.pop()
			pairs.append((v, u))
print(ans)
for i in pairs:
	print(i[0], i[1])