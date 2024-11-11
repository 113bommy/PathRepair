from itertools import accumulate

inf = 10**9 + 1

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]
    ad = [abs(a[i + 1] - a[i]) for i in range(n - 1)]

    ap = [0] + list(accumulate(ai*(-1)**i for i, ai in enumerate(ad)))
    max_dif, max_mdif = max_min_profit(ap)
    ans = max(max_dif, max_mdif)

    print(ans)

def max_min_profit(a):
    max_dif = 0
    max_mdif = 0
    min_v = max_v = 0

    for i in range(1, len(a)):
        if a[i] < min_v:
            min_v = a[i]
        else:
            max_dif = max(max_dif, a[i] - min_v)

        if a[i] > max_v:
            max_v = a[i]
        else:
            max_mdif = max(max_mdif, max_v - a[i])

    return max_dif, max_mdif

if __name__ == '__main__':
    solve()
