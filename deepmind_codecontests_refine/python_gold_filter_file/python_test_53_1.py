def make_them_equal(s, n, c):
    if s[-1] == c:
        for ch in s:
            if ch != c:
                print(1)
                print(n)
                return
        print(0)
        return

    for i in range(1, n):
        if (n - 2 * i) <= 0:
            break

        if s[n - 1 - i] == c:
            print(1)
            print(n - i)
            return

    print(2)
    print(f"{n} {n - 1}")
    return


t = int(input())
for _ in range(t):
    n, c = input().split()
    n = int(n)
    s = input()
    make_them_equal(s, n, c)
