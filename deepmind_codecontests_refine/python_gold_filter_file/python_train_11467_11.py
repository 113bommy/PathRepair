# -*- coding: utf-8 -*-
# @Time    : 2019/2/20 0:12
# @Author  : LunaFire
# @Email   : gilgemesh2012@gmail.com
# @File    : D1. Coffee and Coursework (Easy version).py


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    c = a.copy()
    for i in range(1, n):
        c[i] = c[i] + c[i - 1]
    # print(c)

    dp = [[0] * n for _ in range(n)]
    # print('1st:')
    for i in range(n):
        dp[0][i] = max(0, c[i] - (1 + i) * i // 2)
        if dp[0][i] >= m:
            print(1)
            return
    # print(*dp[0])

    for i in range(1, n):
        for j in range(i, n):
            for k in range(i - 1, j):
                num = j - k - 1
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + c[j] - c[k] - (1 + num) * num // 2)
            if dp[i][j] >= m:
                print(i + 1)
                return

    print(-1)


if __name__ == '__main__':
    main()