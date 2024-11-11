N = int(input())
abc = [[int(j) for j in input().split()] for i in range(N)]
dp = [[0] * 3]
for i in range(N):
    dp += [[max([dp[-1][p] + abc[i][n] for p in range(3) if p != n]) for n in range(3)]]
print(max(dp[-1]))