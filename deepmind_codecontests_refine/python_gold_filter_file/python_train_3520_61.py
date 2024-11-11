n = int(input())
a = list(map(int, input().split()))

dp = [[-1]*n for i in range(n)]
for i in range(n):
    dp[i][i] = 0
cumsum = [0]
for i in range(n):
    cumsum.append(cumsum[-1] + a[i])

def calc_cost(left, right):
    if dp[left][right] >= 0:
        return dp[left][right]
    min_ = min(calc_cost(left, i) + calc_cost(i+1, right) for i in range(left, right))
    dp[left][right] = cumsum[right+1]-cumsum[left] + min_
    return dp[left][right]

print(calc_cost(0,n-1))