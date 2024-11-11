# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

t = 1
t = int(input())

while t:
    t -= 1

    n = int(input())
    rows = []
    rows.append(input())
    rows.append(input())
    dp = [[0, 0] for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n+1):
        if rows[0][i-1] in ('1', '2'):
            dp[i][0] = dp[i-1][0]
        if rows[1][i-1] in ('1', '2'):
            dp[i][1] = dp[i-1][1]
        rot = ['3', '4', '5', '6']
        if rows[0][i-1] in rot and rows[1][i-1] in rot:
            dp[i][0] = dp[i-1][1]
            dp[i][1] = dp[i-1][0]
    print('YES' if dp[-1][1] else 'NO')
