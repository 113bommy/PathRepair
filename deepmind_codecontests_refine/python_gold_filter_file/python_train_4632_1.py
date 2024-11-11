from sys import stdin


def main():
    n, k, p, x, y = map(int, stdin.readline().split())
    ar = list(map(int, stdin.readline().split()))
    count = 0
    total = 0
    for elm in ar:
        if elm >= y:
            count += 1
        total += elm
    least = n - (n + 1) // 2 + 1
    ok = True
    ans = [0] * (n - k)
    if count >= least:
        total += 1 * (n - k)
        for i in range(n - k):
            ans[i] = 1
    elif least - count <= n - k:
        k1 = least - count
        total += k1 * y + (n - k - k1) * 1
        for i in range(k1):
            ans[i] = y
        for i in range(k1, n - k):
            ans[i] = 1
    else:
        ok = False
    if ok:
        if total > x:
            ok = False
    if not ok:
        print(-1)
    else:
        print(*ans)


if __name__ == '__main__':
    main()
