def main():
    N = int(input())

    if N == 3:
        ans = [2, 5, 63]
    else:
        ans = []
        apnd = ans.append
        n = -(-N // 8)
        if N % 2:
            num = (6, 2, 10, 3, 9, 4, 8, 12)
        else:
            num = (2, 10, 3, 9, 4, 8, 6, 12)
        for i in range(n):
            for j in num:
                apnd(j + 12 * i)
                N -= 1
                if not N:
                    break

    print(*ans, sep=' ')

main()
