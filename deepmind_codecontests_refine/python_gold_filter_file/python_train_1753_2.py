def main():
    K, A, B = map(int, input().split())

    if A >= K:
        print(1)
        exit()
    elif A <= B:
        print(-1)
        exit()

    n, m = divmod(K - A, A - B)
    ans = n * 2 + 1
    a = -A
    b = B
    while m > 0:
        m += b
        a, b = b, a
        ans += 1
    print(ans)

main()
