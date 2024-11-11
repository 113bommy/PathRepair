import collections
import copy
INF = 10000

#入力
N, Ma, Mb = map(int, input().split())
medichine = [tuple(map(int, input().split())) for _ in range(N)]

dp = {}
#dp初期化
dp = collections.defaultdict(lambda:INF)
dp[0,0] = 0

for a, b, c in medichine:
    dp_ = copy.copy(dp)
    for ca,cb in dp.keys():
        dp_[ca+a, cb+b] = min(dp_[ca+a, cb+b], dp[ca,cb]+c)
    dp = dp_    

ans = INF
for ca,cb in dp.keys():
    if ca == cb == 0: continue
    if ca*Mb == cb*Ma:
        ans = min(ans, dp[ca,cb])
        
print(-1 if ans == INF else ans)