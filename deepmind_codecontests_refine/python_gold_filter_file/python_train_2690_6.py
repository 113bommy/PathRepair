H,W=map(int,input().split())
c=[list(map(int,input().split())) for _ in range(10)]

for k in range(10):
	for i in range(10):
		for j in range(10):
			c[i][j] = min(c[i][j], c[i][k] + c[k][j])

ans = 0
for _ in range(H):
	ans += sum([c[x][1] for x in map(int,input().split()) if x != -1])

print(ans)
