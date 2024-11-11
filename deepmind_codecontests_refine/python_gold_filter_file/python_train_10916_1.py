from collections import deque
N, M, K = map(int, input().split())
A = list(map(int, input().split()))

#dp[i][j]: i番目の的をj回目にあてた時のpointの最大値
dp = [0] * (N + 1)
for j in range(K):
    newDP = [0] * (N + 1)
    que = deque()  # val, index
    for i in range(j, N - K + j + 1):
        while que and que[-1][0] < dp[i]:
            que.pop()
        que.append((dp[i], i))
        while que and que[0][1] <= i - M:
            que.popleft()
        newDP[i+1] = que[0][0] + (j+1)*A[i]
    dp = newDP

print(max(dp))