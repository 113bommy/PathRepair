
import sys
 
import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
 
 
def solve_tc(dp):
    mod = 1000000000 + 7
    n, m = map(int, input().split())
    cnt = 0
    while n > 0:
        x = int(n % 10)
        if m + x < 10:
            cnt += 1
        else:
            cnt += dp[m + x - 10]
        cnt = int(cnt % mod)
        n //= 10
    return str(cnt)
 
 
def dp_maker():
    max_n = 200005
    mod = 1000000007
    dp = {}
    for i in range(10):
        dp[i] = 2
    dp[9] = 3
    for i in range(10, max_n):
        dp[i] = (dp[i - 9] + dp[i - 10]) % mod
 
    return dp
 
 
dp = dp_maker()
t = int(input())
while t > 0:
    t -= 1
    sys.stdout.write(solve_tc(dp))
    sys.stdout.write("\n")