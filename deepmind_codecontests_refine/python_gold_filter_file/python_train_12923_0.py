def main():
    n, b = map(int, input().split())

    i, ans = 2, 10**19
    while i <= b:
        if i * i > b:
            i = b
        cnt, temp, x = 0, 0, 1

        while b % i == 0:
            b //= i
            cnt += 1

        if cnt == 0:
            i += 1
            continue

        while x <= n // i:
            x *= i
            temp += n // x

        ans = min(ans, temp // cnt)
        i += 1

    print(ans)


main()
