from itertools import product

n = int(input())
F = [list(map(int,input().split())) for i in range(n)]
P = [list(map(int,input().split())) for i in range(n)]

ans = []
for p in product([0,1],repeat = 10):
	if sum(p) == 0:
		continue
	res = 0
	for i in range(n):
		cnt = 0
		for j in range(10):
			if p[j]:
				cnt += F[i][j]
		res += P[i][cnt]
	ans.append(res)
print(max(ans))