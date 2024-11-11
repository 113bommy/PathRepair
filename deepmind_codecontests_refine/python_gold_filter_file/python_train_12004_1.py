# From Tutorial 
from collections import defaultdict, Counter
from sys import stdin
input = stdin.readline
n = int(input()) 
a = list(map(int, input().split()))
fq = Counter()
fl = defaultdict(lambda: [n+1, -1])
for i, el in enumerate(a):
    fl[el][0] = min(fl[el][0], i)
    fl[el][1] = i
    fq[el] += 1
cnt = Counter()
dp = [0] * (n+1)
for i in range(n-1, -1, -1):
    el = a[i]
    cnt[el] += 1
    dp[i] = dp[i+1]
    if i == fl[el][0]:
        dp[i] = max(dp[i], dp[fl[el][1] + 1] + fq[el])
    else:
        dp[i] = max(dp[i], cnt[el])
print(max(n - dp[0], 0))