n, k = map(int, input().split())
As = list(map(int, input().split()))

from itertools import accumulate
acc = [0]+list(accumulate(As))
dp = [0] * 50
mx = 0
sums = []
for i in range(n+1):
    for j in range(i+1,n+1):
        s = acc[j]-acc[i]
        sums.append(s)

# 最大の桁数
for d in range(50):
    if max(sums) & (1<<d):
        mx = max(mx, d)
        dp[d] += 1
mx = 0
for i in range(50):
    if dp[i] >= k:
        mx = max(mx,i)

# 計算
ans = 0
now = 0
for d in range(50,-1,-1):
    cnt = 0
    for s in sums:
        if s & (now+(1<<d)) == now+(1<<d):
            cnt += 1
    # print(d,cnt)
    if cnt >= k:
        now += 1<<d
print(now)