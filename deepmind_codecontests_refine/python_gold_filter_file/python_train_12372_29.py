N = int(input())
A = [[int(x) for x in input().split()] for _ in range(N)]

flag = True
for k in range(N):
	for i in range(N):
		for j in range(i):
			if A[i][j] > A[i][k] + A[k][j]:
				flag = False
				break
		if not flag:
			break
	if not flag:
		break

ans = 0
if flag:
	for i in range(N):
		for j in range(i):
			flag = True
			for k in range(N):
				if k != i and k != j:
					if A[i][j] == A[i][k] + A[k][j]:
						flag = False
						break
			if flag:
				ans += A[i][j]
	print(ans)
else:
	print(-1)