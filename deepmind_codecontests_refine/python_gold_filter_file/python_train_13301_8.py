import sys
input = lambda: sys.stdin.readline().rstrip()
r, c, k = map(int, input().split())
pt = [[0 for _ in range(c + 5)] for _ in range(r + 5)]

for i in range(k):
    r1, c1, v = map(int, input().split())
    pt[r1][c1] = v

memo = [[0] * 4 for _ in range(c + 1)]
prev = [[0] * 4 for _ in range(c + 1)]
for i in range(1, r + 1):
    memo, prev = prev, memo
    for j in range(1, c + 1):
        V = pt[i][j]
        memo[j][0] = max(prev[j][3], memo[j - 1][0])
        memo[j][1] = max(memo[j][0] + V, memo[j - 1][1])
        memo[j][2] = max(memo[j][1], memo[j - 1][1] + V, memo[j - 1][2])
        memo[j][3] = max(memo[j][2], memo[j - 1][2] + V, memo[j - 1][3])
print(memo[-1][3])
