H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
B = [list(map(int, input().split())) for _ in range(H)]

AB = [list(map(lambda x, y: abs(x - y), a, b)) for a, b in zip(A, B)]
dp = [[[0] * 12801 for _ in range(W + 1)] for _ in range(H + 1)]
dp[0][0][0] = 1

for h in range(H):
    for w in range(W):
        ab = AB[h][w]
        for i in range(10000):
            if dp[h][w][i] == 1:
                dp[h+1][w][i+ab] = 1
                dp[h+1][w][abs(i-ab)] = 1
                dp[h][w+1][i+ab] = 1
                dp[h][w+1][abs(i-ab)] = 1

for i in range(1000):
    if dp[H][W-1][i] == 1:
        print(i)
        break
