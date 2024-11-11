
def main():
    s = list(map(int, list(input())))
    n = len(s)
    dp = [1]
    mod = 998244353
    for i, c in enumerate(s):
        dp2 = [0]*(i+2)
        for r in range(i+1):
            if r+c > 0:
                dp2[r+c-1] = (dp2[r+c-1]+dp[r]) % mod
            if i+2-r-c > 0:
                dp2[r+c] += (dp2[r+c]+dp[r]) % mod
        dp = dp2
    for i in range(n):
        dp2 = [0]*(n-i)
        for r in range(n-i+1):
            if r > 0:
                dp2[r-1] = (dp2[r-1]+dp[r]) % mod
            if n-i-r > 0:
                dp2[r] = (dp2[r]+dp[r]) % mod
        dp = dp2
    print(dp[0] % mod)


main()
