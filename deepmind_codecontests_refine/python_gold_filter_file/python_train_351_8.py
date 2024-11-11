def main():
    n = int(input())
    aa = list(map(int, input().split()))
    m = max(aa)
    d = m * n - sum(aa)
    if m > d:
        m += (m - d + n - 2) // (n - 1)
    print(m)


if __name__ == '__main__':
    main()
