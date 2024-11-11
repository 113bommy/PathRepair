import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s); sys.stdout.write('\n')
def wi(n): sys.stdout.write(str(n)); sys.stdout.write('\n')
def wia(a, sep=' '): sys.stdout.write(sep.join([str(x) for x in a])); sys.stdout.write('\n')


def can(t, n, x, a):
    cnt = 0
    mx = 10**9 + 1

    c = 0
    mn = mx
    for i in range(n):
        c += 1
        mn = min(mn, a[i])
        if c * mn >= x:
            cnt += 1
            c = 0
            mn = mx
            if cnt >= t:
                return True
    return False


def solve(n, x, a):
    a = sorted(a, reverse=True)
    lo = 0
    hi = n + 1
    while hi > lo + 1:
        mid = (lo + hi) // 2
        if can(mid, n, x, a):
            lo = mid
        else:
            hi = mid
    return lo


def main():
    for _ in range(ri()):
        n, x = ria()
        a = ria()
        wi(solve(n, x, a))


if __name__ == '__main__':
    main()
