from itertools import accumulate

def solve(left, right):
    if left == right:
        return 0
    ret = dp[left][right]
    if ret > 0:
        return ret
    ret = inf
    for mid in range(left, right):
        ret = min([ret, solve(left, mid)+solve(mid+1, right)])
    ret += s[right] - (s[left-1] if left > 0 else 0)
    dp[left][right] = ret
    return ret

inf = 10**15
N = int(input())
A = list(map(int, input().split()))
s = list(accumulate(A))
dp = [[0]*(N) for _ in range(N)]
print(solve(0, N-1))
