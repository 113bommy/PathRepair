def solve():
    rd = lambda : list(map(int, input().split()))
    n = int(input())
    p = []
    for i in range(n):
        p.append(input())
    dp = [0 for i in range(n)]
    dp[0] = 1
    indent = 0
    L = int(1e9 + 7)
    for i, val in enumerate(p):
        if val == 'f':
            indent += 1
        else:
            for j in range(1, indent + 1):
                dp[j] = (dp[j - 1] + dp[j]) % L
    print(dp[indent])

solve()