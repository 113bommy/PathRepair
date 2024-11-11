from collections import defaultdict

N, Ma, Mb = map(int, input().split())

dp = [defaultdict(lambda : float('inf')) for _ in range(2)]
zero = float('inf')

dp[0][0] = dp[1][0] = 0

for _ in range(N) :
    a, b, c = map(int, input().split())
    d = a * Mb - b * Ma
    if d == 0 :
        zero = min(zero, c)
    else :
        i = 0 if d > 0 else 1
        d = abs(d)
        item = list(dp[i].items())[::-1]
        for k, v in item :
            dp[i][k+d] = min(dp[i][k+d], dp[i][k] + c)

ret = zero       
for k, v in dp[0].items() :
    if k in dp[1] and k != 0 :
        ret = min(ret, v + dp[1][k])
        
if ret == float('inf') :
    print(-1)
else :
    print(ret)