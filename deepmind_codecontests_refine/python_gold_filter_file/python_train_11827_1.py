from sys import stdin


def check(n, s, a):
    a.sort(key=lambda x: x[1] * n + x[0])
    r = 0
    for i in a[:n]:
        r += i[0] + i[1] * n
    return r


def main():
    n, s = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    for i in range(n):
        a[i] = [a[i], i + 1]
    l = 0
    res = 0
    r = n + 1
    while r - l > 1:
        m = (l + r) // 2
        b = a[:]
        res_new = check(m, s, b)
        if res_new <= s:
            l = m
            res = res_new
        else:
            r = m
    print(l, res)


main()