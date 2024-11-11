N = int(input())

F = [int(input().replace(" ", ""), 2) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]


profit = float("-inf")

for i in range(1,1024):
	tmp = 0
	tmp2 = 0
	for j in range(N):
		tmp = (bin(i & F[j]).count('1'))
		tmp2 = tmp2 + P[j][tmp]
	profit = max(profit, tmp2)

print(profit)