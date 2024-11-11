def f(k):
    res = []
    d = 2
    while d * d <= k:
        if k % d == 0:
            res.append(d)
            k //= d
        else:
            d += 1
    if k != 1:
        res.append(k)
    return res


def main():
    l, r, x, y = map(int, input().split())
    if y % x != 0:
        return 0
    if y == x:
        if l <= x <= r:
            return 1
        else:
            return 0
    a = f(x)
    b = f(y)
    for i in range(len(a)):
       b = b[:b.index(a[i])] + b[b.index(a[i]) + 1:]
    ans = 0
    a = [b[0]]
    for i in range(1, len(b)):
        if b[i] == b[i - 1]:
            a[-1] *= b[i]
        else:
            a.append(b[i])
    for i in range(2 ** len(a)):
        c1 = 1
        c2 = 1
        for j in range(len(a)):
            if (2 ** j) & i:
                c1 *= a[j]
            else:
                c2 *= a[j]
        if l <= x * c1 <= r and l <= x * c2 <= r:
            ans += 1
    return ans
    
print(main())
