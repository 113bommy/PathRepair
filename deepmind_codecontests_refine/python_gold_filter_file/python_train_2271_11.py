import sys

n = int(input())
blocks = []
for line in sys.stdin.readlines():
    w, s, v = map(int, line.split())
    blocks.append((w + s, w, s, v))
blocks.sort()

dp = [-1] * 20001
dp[0] = 0
for _, w, s, v in blocks:
    for i in range(min(s, 20000 - w), -1, -1):
        dp[i + w] = max(dp[i + w], dp[i] + v)
print(max(dp))
