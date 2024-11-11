import sys

N = int(input())
E = [list(map(int, input().split())) for _ in range(N)]

inf = float('inf')
for i in range(N):
	E[i][i] = inf

for k in range(N):
	for i in range(N):
		if i == k:
			continue
		for j in range(N):
			if k == j or i == j:
				continue
			direct = E[i][j]
			detour = E[i][k]+E[k][j]
			if direct == inf or detour == inf:
				continue

			if direct > detour:
				print(-1)
				sys.exit()

			elif direct == detour:		
				E[i][j] = inf
				E[j][i] = inf

answer = 0
for i in range(N):
	for j in range(N):
		if E[i][j] == inf:
			continue
		
		answer += E[i][j]

print(answer//2)