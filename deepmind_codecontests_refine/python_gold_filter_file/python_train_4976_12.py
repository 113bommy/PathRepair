import sys
input = sys.stdin.readline
sys.setrecursionlimit(pow(10, 6))


def main():
    n, m = map(int, input().split())
    edges = [[] for _ in range(n)]
    for _ in range(m):
        s, t = map(int, input().split())
        edges[s-1].append(t-1)
    
    ans = n + 1
    for i in range(n - 1):
        # 頂点 i からの辺を消す
        dp = [0 for _ in range(n)]

        for j in range(n - 2, -1, -1):
            totale, maxe = 0, 0
            for e in edges[j]:
                totale += dp[e]
                maxe = max(maxe, dp[e])
        
            if i == j and len(edges[j]) > 1:
                dp[j] = (totale - maxe) / (len(edges[j]) - 1) + 1
            else:
                dp[j] = totale / len(edges[j]) + 1
        
        ans = min(ans, dp[0])
    
    print("%.10f" % ans)


if __name__ == '__main__':
    main()
