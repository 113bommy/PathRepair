def main():
    n = int(input())
    if n < 3:
        print(-1)
    else:
        print(*list(range(n, 0, -1)))


main()
