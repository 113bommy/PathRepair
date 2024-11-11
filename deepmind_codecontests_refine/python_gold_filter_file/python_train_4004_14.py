from sys import stdin


def bin_pow(a, n):
    if n == 0:
        return 1
    if n % 2:
        return a * bin_pow(a * a, (n - 1) // 2)
    else:
        return bin_pow(a * a, n // 2)


INF = 10 ** 9


def main():
    line = stdin.readline
    a, b, c = map(int, line().split())

    answers = []
    for s in range(81):
        v = b * bin_pow(s, a) + c
        if v <= 0 or v >= INF:
            continue
        sum_digits = sum(int(c) for c in str(v))
        if sum_digits == s:
            answers.append(v)
    print(len(answers))
    for ans in answers:
        print(ans, end=' ')


if __name__ == '__main__':
    main()
