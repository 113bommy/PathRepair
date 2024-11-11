from sys import stdin


def solve(n, k, d1, d2):
    if (d1 + 2 * d2 + k) % 3 != 0:
        return False

    c = (d1 + 2 * d2 + k) // 3
    a = c - d1 - d2
    b = k - a - c

    if a >= 0 and b >= 0 and c >= 0 and a + b + c == k:
        _max = max(a, b, c)
        diff = sum(_max - e for e in [a, b, c])
        d = n - k
        if d >= diff and (d - diff) % 3 == 0:
            return True

    return False


def main():
    test = stdin.readlines()
    output = []
    for i in range(1, int(test[0]) + 1):
        n, k, d1, d2 = map(int, test[i].split())
        for i, j in [(-1, -1), (-1, 1), (1, -1), (1, 1)]:
            if solve(n, k, i * d1, j * d2):
                output.append('yes')
                break
        else:
            output.append('no')

    print('\n'.join(output))


if __name__ == "__main__":
    main()
