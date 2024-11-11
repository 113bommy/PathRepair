import sys


n, m = map(int, sys.stdin.buffer.readline().decode('utf-8').split())
a = list(map(int, sys.stdin.buffer.readline().decode('utf-8').split()))
dp = [0]*(m+1)

for x in a:
    if x <= m:
        dp[x] += 1

for i in range(m, 0, -1):
    for j in range(2, m+1):
        if i*j > m:
            break
        dp[i*j] += dp[i]

lcm = max(1, dp.index(max(dp)))
ans = [i for i, x in enumerate(a, start=1) if lcm % x == 0]

sys.stdout.buffer.write(
    (str(lcm) + ' ' + str(len(ans)) + '\n' +
     ' '.join(map(str, ans))).encode('utf-8')
)
