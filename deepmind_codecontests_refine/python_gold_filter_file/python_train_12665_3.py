def scan():
	for i in range(n):
		for j in range(n - k + 1):
			f = True
			for l in range(k):
				if a[i][j + l] == "#":
					f = False
					break

			if f:
				for l in range(k):
					b[i][j + l] += 1



n,k = input().split()
n = int(n)
k = int(k)
a = [[]]
b=[[]]
for i in range(n):
	wk1 = input()
	for j in range(n):
		a[i].append(wk1[j])
		b[i].append(0)
	a.append([])
	b.append([])
	

scan()


for i in range(n):
	for j in range(i,n):
		if i != j :
			wk1 = a[i][j]
			a[i][j] = a[j][i]
			a[j][i] = wk1
			wk1 = b[i][j]
			b[i][j] = b[j][i]
			b[j][i] = wk1
			
scan()


ans_max = 0
anx_x = 1
anx_y = 1
for i in range(n):
	for j in range(n):
		if ans_max < b[j][i]:
			ans_max = b[j][i]
			anx_x = i + 1
			anx_y = j + 1


print(anx_x,anx_y)

