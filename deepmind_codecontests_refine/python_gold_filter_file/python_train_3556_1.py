n, m = map(int, input().strip().split())
g=[]
wolves=[]
for i in range(0,n):
	g.append(list(input().strip()))
	for j in range(0, m):
		if g[-1][j]=='W':
			wolves.append([i, j])
gr=0
for i in wolves:
	if i[0]-1>-1:
		if g[i[0]-1][i[1]]=='P':
			gr+=1
			continue

	if i[0] +1 < n:
		if g[i[0]+1][i[1]]=='P':
			gr+=1
			continue

	if i[1]-1>-1:
		if g[i[0]][i[1]-1]=='P':
			gr+=1
			continue

	if i[1]+1<m:
		if g[i[0]][i[1]+1]=='P':
			gr+=1
			continue
print(gr)