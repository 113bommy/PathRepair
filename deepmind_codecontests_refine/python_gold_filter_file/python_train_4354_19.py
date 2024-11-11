n=int(input())
v=list(map(int, input().split()))
dp=[[-1] * n for i in range(n)]
def f(a, b):
    if a > b:
        return 0
    elif a == b:
        return v[a]
    elif dp[a][b] == -1:
        c1 = v[a] + min(f(a + 2, b), f(a + 1, b - 1))
        c2 = v[b] + min(f(a, b - 2), f(a + 1, b - 1))
        dp[a][b] = max(c1, c2)
    return dp[a][b]

print(2*f(0, n-1) - sum(v))