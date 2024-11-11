#!/usr/bin/env python

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    mod = 10**9+7

    a.sort()
    ret = 1
    if k % 2 == 0 or a[-1] >= 0:
        l = 0
        r = -1
        mlt1 = a[0] * a[1]
        mlt2 = a[-2] * a[-1]
        for _ in range(k//2):
            if mlt1 >= mlt2:
                ret *= mlt1 % mod
                l += 2
                if l <= n-2:
                    mlt1 = a[l+1] * a[l]
            else:
                ret *= mlt2 % mod
                r -= 2
                if r >= -n+1:
                    mlt2 = a[r-1] * a[r]
            ret %= mod

        if k % 2 == 1:
            ret *= a[r]
            ret %= mod

    else:
        for i in range(k):
            ret *= a[n-1-i]
            ret %= mod

    print(ret)


if __name__ == '__main__':
    main()
