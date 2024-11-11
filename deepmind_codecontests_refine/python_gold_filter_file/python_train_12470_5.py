from operator import itemgetter
import bisect


n, t = map(int, input().split())
info = [list(map(int, input().split())) for i in range(n)]
INF = t + 1
LIMIT = 60

# mrkt_a0: a == 0 の店
# mrkt_others: a != 0 の店
mrkt_a0 = []
mrkt_others = []

for i in range(n):
    a, b = info[i]
    if a == 0:
        mrkt_a0.append((a, b))
    else:
        comp = a / (1 + b)
        mrkt_others.append((a, b, comp))

mrkt_a0.sort(key=itemgetter(1))
mrkt_others.sort(key=itemgetter(2), reverse=True)

# mrkt_a0について
# もしmarkt_a0を尋ねるなら尋ねるのを後回しにしたほうが良い
times_a0 = [0]
for a, b in mrkt_a0:
    times_a0.append(times_a0[-1] + 1 + b)

# mrkt_othersについて
len_others = len(mrkt_others)
dp = [[INF] * LIMIT for i in range(len_others + 1)]
dp[0][0] = 0

for i in range(len_others):
    a, b, _ = mrkt_others[i]
    for cnt in range(LIMIT):
        # i番目の店を尋ねないとき
        dp[i + 1][cnt] = min(dp[i][cnt], dp[i + 1][cnt])
        # i番目の店を尋ねるとき
        if cnt + 1 < LIMIT:
            dp[i + 1][cnt + 1] = min(a * (dp[i][cnt] + 1) + b + dp[i][cnt] + 1, dp[i + 1][cnt + 1])

ans = 0
for cnt in range(LIMIT):
    if dp[-1][cnt] == t + 1:
        continue
    nokori = t - dp[-1][cnt]
    cnt_a0 = bisect.bisect_right(times_a0, nokori) - 1
    ans = max(ans, cnt + cnt_a0)

print(ans)