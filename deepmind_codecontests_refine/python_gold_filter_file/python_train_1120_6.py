n, k = map(int, input().split())
cum = [0, 1]
dp = [0, 1]

lr = [list(map(int, input().split())) for _ in range(k)]    
mod = 998244353
# i: 目標のマス
def check(i):
    res = 0
    for l, r in lr:
        if i - l < 1:
            continue
        res += cum[i-l] - cum[max(i-r-1,0)]
        res %= mod
    return res


for i in range(2,n+1):
    dp.append(check(i))
    cum.append((cum[-1]+dp[-1])%mod)

print(dp[-1])