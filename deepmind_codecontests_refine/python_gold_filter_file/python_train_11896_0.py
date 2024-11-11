import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def main():
    n, d, m = map(int, input().split())
    small, big = [], []
    for x in map(int, input().split()):
        if x > m:
            big.append(x)
        else:
            small.append(x)

    small.sort()
    big.sort(reverse=True)

    if not big:
        print(sum(small))
        exit()

    n -= 1
    ans = big.pop(0)
    big = [big[i] for i in range(min(len(big), n // (d + 1)))]
    ans += sum(small.pop() for i in range(min(len(small), n - (len(big) * (d + 1)))))

    while small and big:
        x = sum(small.pop() for i in range(min(len(small), d + 1)))
        ans += max(x, big.pop())

    print(ans + sum(big))


if __name__ == '__main__':
    main()
