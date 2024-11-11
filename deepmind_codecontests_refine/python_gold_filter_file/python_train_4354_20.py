import sys 
input = sys.stdin.readline
MOD = 10**9 +7
INF = 10**9

def main():
    n = int(input())
    a = list(map(int,input().split()))
    
    dp = [[0] * (n + 2)  for _ in range(n + 2)]
    
    for l in range(1,n + 1):
        for i in range(n - l + 1):
            j = i + l
            if (n - l)%2 == 0:
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1])
            else:
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1])
    
    print(dp[0][n])

if __name__=='__main__':
    main()