s, n = map(int, input().split())
z = []
for _ in range(n):
	x, y = map(int, input().split())
	z.append((x, y))
z.sort(key = lambda x:x[0])
flag = True
for i in z:
	if i[0] < s:
		s+=i[1]
	else:
		flag = False
		break
if flag:
	print('YES')
else:
	print('NO')