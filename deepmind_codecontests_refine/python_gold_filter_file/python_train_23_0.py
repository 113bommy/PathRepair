line = input().split()
n,k = int(line[0]), int(line[1])

a,b,c = [],[],[]

for i in range(n):
	line = input().split()
	t,ai,bi = int(line[0]), int(line[1]), int(line[2])
	if (ai == 1 and bi == 1):
		c.append(t)
	elif (ai == 1):
		a.append(t)
	elif (bi == 1):
		b.append(t)

a.sort()
b.sort()
c.sort()

i,j,cnt = 0,0,0
ans = 0

while (i < min(len(a),len(b)) and j < len(c) and cnt < k):
	if (a[i]+b[i] < c[j]):
		ans += a[i]+b[i]
		i += 1
	else:
		ans += c[j]
		j += 1
	cnt += 1

while (i < min(len(a),len(b)) and cnt < k):
	ans += a[i]+b[i]
	cnt += 1
	i += 1

while (j < len(c) and cnt < k):
	ans += c[j]
	cnt += 1
	j += 1

if (cnt < k):
	print(-1)
else:
	print(ans)

	

	