def solve(n, a):
    from itertools import accumulate

    inf = (400 ** 2) * (10 ** 9) + 10

    # [l,r)
    def dfs(l, r):
        if memo[l][r] != -1:
            return memo[l][r]
        if r - l == 1:
            return 0
        res = inf
        for c in range(l + 1, r):
            # [l, c), [c, r)
            res = min(res, dfs(l, c) + dfs(c, r))
        res += acc[r] - acc[l]
        memo[l][r] = res
        return res

    acc = (0,) + tuple(accumulate(a))
    memo = [[-1] * (n + 1) for _ in range(n + 1)]

    return dfs(0, n)


if __name__ == '__main__':
    n = int(input())
    a = tuple(map(int, input().split()))
    print(solve(n, a))
