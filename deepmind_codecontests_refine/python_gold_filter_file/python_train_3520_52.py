import sys
sys.setrecursionlimit(10**8)

N = int(input())
*a, = map(int, input().split())

s = [0]*N
s[0] = a[0]
for i in range(1, N):
    s[i] += s[i-1]+a[i]
s = [0]+s

dp = [[0]*(N+1) for _ in range(N+1)]


def solve(l, r):
    if l == r:
        return 0
    if dp[l][r] > 0:
        return dp[l][r]

    n = float('inf')
    m = s[r+1]-s[l]
    for i in range(l, r):
        n = min([n, solve(l, i)+solve(i+1, r)+m])
    dp[l][r] = n
    return n


print(solve(0, N-1))
