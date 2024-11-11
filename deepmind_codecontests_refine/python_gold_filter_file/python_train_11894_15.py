def solve(n):
    if n <= 3:
        print(-1)
        return

    for i in range(0, n // 4 - 1):
        print(i * 4 + 2, end=' ')
        print(i * 4 + 4, end=' ')
        print(i * 4 + 1, end=' ')
        print(i * 4 + 3, end=' ')

    i = n // 4 - 1

    if n % 4 == 0:
        print(i * 4 + 2, end=' ')
        print(i * 4 + 4, end=' ')
        print(i * 4 + 1, end=' ')
        print(i * 4 + 3, end=' ')
    elif n % 4 == 1:
        print(i * 4 + 2, end=' ')
        print(i * 4 + 4, end=' ')
        print(i * 4 + 1, end=' ')
        print(i * 4 + 3, end=' ')
        print(i * 4 + 5, end=' ')
    elif n % 4 == 2:
        print(i * 4 + 2, end=' ')
        print(i * 4 + 4, end=' ')
        print(i * 4 + 6, end=' ')
        print(i * 4 + 3, end=' ')
        print(i * 4 + 1, end=' ')
        print(i * 4 + 5, end=' ')
    elif n % 4 == 3:
        print(i * 4 + 2, end=' ')
        print(i * 4 + 4, end=' ')
        print(i * 4 + 6, end=' ')
        print(i * 4 + 3, end=' ')
        print(i * 4 + 1, end=' ')
        print(i * 4 + 5, end=' ')
        print(i * 4 + 7, end=' ')

    print()


def main():
    t = int(input())

    for i in range(t):
        n = int(input())
        solve(n)

    return 0


main()

