N = int(input())
GA, SA, BA = map(int, input().split())
GB, SB, BB = map(int, input().split())

def napsac(x, g1, s1, b1, g2, s2, b2):
    dp = [0 for _ in range(x+1)]
    dp[0] = 0

    def case(i, m1, m2):
        return 0 if i - m1 < 0 else dp[i-m1] + m2

    for i in range(1,x+1):
        dp[i] = max(i, case(i, g1, g2), case(i, s1, s2), case(i, b1, b2))

    return dp[-1]

print(napsac(napsac(N, GA, SA, BA, GB, SB, BB), GB, SB, BB, GA, SA, BA))
