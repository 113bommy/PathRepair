def printt(s):
    for i in s:
        print(" ".join([str(x) for x in i]))


def task():
    n = int(input())
    if n == 1:
        print(1)
        return
    elif n == 2:
        print(-1)
        return
    elif n == 3:
        printt([[1, 8, 6], [7, 5, 3], [4, 2, 9]])
        return
    s = [[j * n + i + 1 for i in range(n)] for j in range(n)]

    for i in range(n // 2):
        for j in range(n):
            if (i + j) & 1:
                s[i][j] ^= s[n - i - 1][j]
                s[n - i - 1][j] ^= s[i][j]
                s[i][j] ^= s[n - i - 1][j]

    if n & 1:
        for i in range(n // 2 - 2):
            if i & 1:
                s[n // 2][i] ^= s[n // 2][n - i - 1]
                s[n // 2][n - i - 1] ^= s[n // 2][i]
                s[n // 2][i] ^= s[n // 2][n - i - 1]

        m = s[n // 2][n // 2]
        s[n // 2][n // 2 - 2], s[n // 2][n // 2 - 1], s[n // 2][n // 2 + 1], s[n // 2][n // 2 + 2] = m-1, m+2, m-2, m+1

    printt(s)


if __name__ == '__main__':
    for i in range(int(input())):
        task()
