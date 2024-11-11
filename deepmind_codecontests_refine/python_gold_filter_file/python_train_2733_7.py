import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')


def solve(n, a):
    b = [i for i in range(n)]
    b = sorted(b, key=lambda x: (a[x], x))

    res = []
    for it in range(n):
        for i in range(n-1):
            if b[i+1] < b[i]:
                b[i], b[i+1] = b[i+1], b[i]
                res.append([b[i]+1, b[i+1]+1])

    wi(len(res))
    for i in range(len(res)):
        wia(res[i])


def main():
    n = ri()
    a = ria()
    solve(n, a)


if __name__ == '__main__':
    main()
