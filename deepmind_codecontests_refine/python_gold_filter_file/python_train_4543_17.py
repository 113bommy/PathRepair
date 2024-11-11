def fast_p(x, y, mod):
    if y == 0:
        return 1

    if y % 2:
        return (x * fast_p(x, y - 1, mod)) % mod
    else:
        t = fast_p(x, y // 2, mod)
        return (t * t) % mod


def main():
    n, m, k = map(int, input().split())
    if (n + m) % 2 and k == -1:
        print(0)
        return
    
    y = (n - 1) * (m - 1)
    t1 = fast_p(2, n-1, 1000000007)
    print(fast_p(t1, m-1, 1000000007))


if __name__ == '__main__':
    main()