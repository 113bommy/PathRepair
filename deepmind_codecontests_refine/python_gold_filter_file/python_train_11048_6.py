d = {}
n = int(input())
a = []
n2 = n
n = 2*n
for _ in range(n):
	b,c = map(int,input().split())
	a.append((b,c))

for i in range(1,n):
	xsum = a[0][0] + a[i][0]
	ysum = a[0][1] + a[i][1]
	d = {}
	for j in range(1,n):
		try:
			d[a[j]] += 1
		except:
			d[a[j]] = 1
	d[a[i]] -= 1
	flag = 0
	# print(xsum,ysum)
	for j in range(1,n):
		if d[a[j]] > 0:
			d[a[j]] -= 1
			xtemp = xsum - a[j][0]
			ytemp = ysum - a[j][1]
			try:
				if d[(xtemp,ytemp)] > 0:
					d[(xtemp,ytemp)] -= 1
				else:
					flag = 1
					break
			except:
				flag = 1
				break
	# print(flag)
	if flag == 0:
		print(xsum,ysum)
		break
