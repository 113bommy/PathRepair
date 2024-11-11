# K - Stones
def main():
    N, K, *A = map(int, open(0).read().split())
    dp = [0] * (K + 1)
    for i in range(K):
        for a in A:
            if i + a > K:
                break
            dp[i + a] |= dp[i] ^ 1
    print("First" if dp[-1] else "Second")


if __name__ == "__main__":
    main()
