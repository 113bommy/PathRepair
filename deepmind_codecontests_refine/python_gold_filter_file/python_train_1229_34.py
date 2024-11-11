# K - Stones
def main():
    N, K, *A = map(int, open(0).read().split())
    dp = [0] * (K + 1)
    for i in range(1, K + 1):
        for a in A:
            if i - a >= 0:
                dp[i] |= dp[i - a] ^ 1
    print("First" if dp[-1] else "Second")


if __name__ == "__main__":
    main()
