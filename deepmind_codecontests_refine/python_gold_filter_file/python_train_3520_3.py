import sys
input=sys.stdin.readline
sys.setrecursionlimit(100000000)
MOD = 10**9+7
INF = 10 ** 20
from functools  import lru_cache

MAXN = 405
a = [0] * MAXN
dp = [[-1] * MAXN for _ in range(MAXN)]
def dfs(l,r):
    if dp[l][r] != -1:
        return dp[l][r]
    if r - l == 1:
        dp[l][r] = 0
        return 0
    ans = INF
    for i in range(l + 1,r):
        ans = min(ans,dfs(l,i) + dfs(i,r)) 
    if l == 0:
        ans += a[r - 1]
    else:
        ans += a[r - 1] - a[l - 1]
    dp[l][r] = ans
    return ans

def main():
    n = int(input())
    b = list(map(int,input().split()))
    a[:n] = b

    for i in range(1,n):
        a[i] += a[i - 1]
    
    ans = dfs(0,n)
    print(ans)
if __name__=='__main__':
    main()