from bisect import bisect_right

n,r = map(int, input().split())
aa = [0]*n
bb = [0]*n
for i in range(n):
    aa[i], bb[i] = map(int, input().split())
ppi = [(aa[i], bb[i]) for i in range(n) if bb[i] >= 0]
ppd = [(max(aa[i], -bb[i]), bb[i]) for i in range(n) if bb[i] < 0]
ppi.sort()
count = 0
for (a,b) in ppi:
    if a > r:
        break
    r += b
    count+=1
ppd.sort(reverse=True,key=lambda p: p[0] + p[1] )
dp = [[0]*(r+1) for _ in range(len(ppd)+1)]
dp[0][r] = count
for i,(a,b) in enumerate(ppd):
    for v in range(r+1):
        if v >= a and v+b >= 0:
            dp[i+1][v + b] = max(dp[i+1][v + b], dp[i][v] + 1)
        dp[i+1][v] = max(dp[i+1][v], dp[i][v])
print(max(dp[len(ppd)]))