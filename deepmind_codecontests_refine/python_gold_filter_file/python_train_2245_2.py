from sys import stdout
INF = float('inf')
n, k = map(int, input().split())
maps = input().strip()
dp = [INF for i in range(n)]

dp[maps.index('G')] = 0

for i in range(n):
    if dp[i] != INF and i + k < n and maps[i + k] != '#':
        dp[i + k] = 1
        
for i in range(n - 1, - 1, -1):
    if dp[i] != INF and i - k >= 0 and maps[i - k] != '#':
        dp[i - k] = 1

if dp[maps.index('T')] != INF:
    stdout.write('YES')
else:
    stdout.write('NO')