import math


def main():
    n, m = map(int, input().split())
    b = n // 2
    res = -1
    while b >= 0:
        a = n - 2*b
        if (a + b) % m == 0:
            res = a + b
            break
        b -= 1
    print(res)


if __name__ == '__main__':
    main()
