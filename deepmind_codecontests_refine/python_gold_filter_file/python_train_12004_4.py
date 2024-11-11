from collections import Counter
n = int(input())
M = list(map(int, input().split()))
left, right = {}, {}
for i, m in enumerate(M):
    left.setdefault(m, i)
    right[m] = i
dp = [0]*(n+1)
cnt = Counter()
for i in range(n-1, -1, -1):
    dp[i] = dp[i+1]
    cnt[M[i]] += 1
    if i == left[M[i]]:
        dp[i] = max(dp[i], dp[right[M[i]]+1] + cnt[M[i]])
    else:
        dp[i] = max(dp[i], cnt[M[i]])
print(n-dp[0])
