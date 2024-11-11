import sys
input = sys.stdin.readline

def solve():
    N = int(input())
    items = [tuple(map(int, input().split())) for _ in range(N)]

    capW = max([w+s for w, s, v in items])
    items.sort(key=lambda x: x[0]+x[1])

    def knapsack01(items, capW):
        dp = [0] * (capW+1)
        for wi, si, vi in items:
            for w in reversed(range(wi, si+wi+1)):
                v0 = dp[w-wi] + vi
                if v0 > dp[w]:
                    dp[w] = v0
        return max(dp)

    ans = knapsack01(items, capW)
    print(ans)


solve()
