#!/usr/bin/env python3


def main():
    n = int(input())
    mx = [[int(x) for x in input().split()] for _ in range(n)]
    i, j = -1, -1

    if n == 1:
        print(1)
        return

    for ii in range(n):
        if 0 in mx[ii]:
            i = ii
            j = mx[i].index(0)
            break

    sr = [sum(x) for x in mx]
    sc = [sum(x) for x in zip(*mx)]
    sd1 = sum(mx[i][i] for i in range(n))
    sd2 = sum(mx[i][n - i - 1] for i in range(n))

    ii = 0 if i != 0 else 1

    d = sr[ii] - sr[i]

    if d <= 0 or d > 10 ** 18:
        print(-1)
        return

    sr[i] += d
    sc[j] += d

    if i == j:
        sd1 += d
    if j == n - i - 1:
        sd2 += d

    if len(set(sr + sc + [sd1, sd2])) > 1:
        print(-1)
    else:
        print(d)


if __name__ == '__main__':
    main()
