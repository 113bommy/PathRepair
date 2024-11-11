def main():
    INF = 10 ** 15
    N = int(input())
    A = list(map(int, input().split(' ')))
    cumsum = [0 for _ in range(N)]
    cumsum[0] = A[0]
    for i in range(1, N):
        cumsum[i] = A[i] + cumsum[i - 1]
    dp = [[0 for _ in range(N)] for _ in range(N)]

    def solve(left, right):
        if left == right:
            return 0
        ret = dp[left][right]
        if ret > 0:
            return ret
        ret = INF
        for mid in range(left, right):
            ret = min([
                ret,
                solve(left, mid) + solve(mid + 1, right)
            ])
        ret += cumsum[right] - (cumsum[left - 1] if left > 0 else 0)
        dp[left][right] = ret
        return ret

    print(solve(0, N - 1))


if __name__ == '__main__':
    main()
