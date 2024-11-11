# https://codeforces.com/problemset/problem/46/A

n = int(input().strip())
ball_ps = 1
for i in range(1, n):
    ball_ps += i
    if ball_ps > n:
        ball_ps = ball_ps - n
    print(ball_ps, end=' ')
