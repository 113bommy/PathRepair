h,w = map(int,input().split())
d = [list(map(int,input().split())) for _ in range(10)]
for k in range(10):
	for i in range(10):
		for j in range(10):
			d[i][j] = min(d[i][j], d[i][k] + d[k][j])
ans = 0
for _ in range(h):
	for x in map(int,input().split()):
		ans += (x!=-1) * d[x][1]
print(ans)