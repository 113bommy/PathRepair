def main():
    n,K = map(int, input().split())
    h = list(map(int, input().split()))

    DP = [[float("inf")]*(K+1) for i in range(K+1)]
    DP[0][0] = 0
    for i in range(n):
        hi = h[i]
        nxt = [[float("inf")]*(K+1) for i in range(K+1)]
        for j in range(min(i+1, K+1)):
            for k in range(j+1):
                l = i-k-1
                if l<0:
                    left = 0
                else:
                    left = h[l]
                a = hi-left if left<hi else 0
                nxt[j][0] = min(nxt[j][0], DP[j][k]+a)
                if j == K:
                    continue
                nxt[j+1][k+1] = min(nxt[j+1][k+1], DP[j][k])
        DP = nxt

    ans = float("inf")
    for i in DP:
        ans = min(ans, min(i))
    print(ans)

main()