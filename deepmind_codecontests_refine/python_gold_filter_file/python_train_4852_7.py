def main():
    n, m = map(int, input().split())
    a = round(m * n / 180.)
    if not a:
        a = 1
    elif a > n - 2:
        a = n - 2
    print(n, n - 1, a)


if __name__ == '__main__':
    main()
