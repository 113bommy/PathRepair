N = int(input())
F = [list(map(int,input().split())) for i in range(N)]
P = [list(map(int,input().split())) for i in range(N)]

ans = -(10**10)
for i in range(1,1024):
	X = [0]*N
	for j in range(N):
		count = 0
		for k in range(10):
			if (i>>k)&1 == 1 and F[j][k] == 1:
				count += 1
		X[j] = P[j][count]
	ans = max(ans,sum(X))

print(ans)
