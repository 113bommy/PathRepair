def main():
    x, y = map(int, input().split())
    n = int(input())
    if n // 3 % 2:
        if n % 3 == 1:
            print(-x % 1000000007)
        elif n % 3 == 2:
            print(-y % 1000000007)
        else:
            print((y - x) % 1000000007)
    else:
        if n % 3 == 1:
            print(x % 1000000007)
        elif n % 3 == 2:
            print(y % 1000000007)
        else:
            print((x - y) % 1000000007)


main()
