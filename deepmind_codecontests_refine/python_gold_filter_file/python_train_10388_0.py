def main():
    import sys
    sys.setrecursionlimit(10**9)
    input = sys.stdin.readline
    from collections import deque
    from bisect import bisect_left

    N = int(input())
    a = list(map(int, input().split()))
    tree = [[] for _ in [0]*N]
    for u, v in [map(int, input().split()) for _ in [0]*(N-1)]:
        tree[u-1].append(v-1)
        tree[v-1].append(u-1)
    
    dp = [1001001001] * (N+1)
    dp[0] = -1001001001
    ans = [0] * N
    def dfs(now, p=-1):
        idx = bisect_left(dp, a[now])
        old = dp[idx]
        dp[idx] = a[now]
        ans[now] = idx
        if p != -1 and ans[now] < ans[p]:
            ans[now] = ans[p]
        for child in tree[now]:
            if child == p: continue
            dfs(child, now)
        dp[idx] = old
    dfs(0)

    print(*ans, sep='\n')

main()