import os,io
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n = int(input())
a = list(map(int,input().split()))
pos = []
neg = []
dp = [n]*n
dp[0] = 0
for i in range(n):
    while pos and a[pos[-1]]>a[i]:
        dp[i] = min(dp[i],dp[pos[-1]]+1)
        pos.pop()
    if pos:
        dp[i] = min(dp[i],dp[pos[-1]]+1)
        if a[i]==a[pos[-1]]:
            pos.pop()
    pos.append(i)

    while neg and a[neg[-1]]<a[i]:
        dp[i] = min(dp[i],dp[neg[-1]]+1)
        neg.pop()
    if neg:
        dp[i] = min(dp[i],dp[neg[-1]]+1)
        if a[i]==a[neg[-1]]:
            neg.pop()
    neg.append(i)
print(dp[-1])