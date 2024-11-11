
def main() :
    a = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    n, k = map(int, input().split())
    print(1 + (a[n-1] - (8 - k) + 6) // 7)

    return 0


main()