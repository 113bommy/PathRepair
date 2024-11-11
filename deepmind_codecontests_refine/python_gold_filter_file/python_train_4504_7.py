import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a, sep=' '): sys.stdout.write(sep.join([str(x) for x in a]) + '\n')


def solve(n, m, a):
    for i in range(n):
        for j in range(m):
            if a[i][j] == 0:
                continue
            nns = 4
            if i == 0 or i == n-1:
                nns -= 1
            if j == 0 or j == m-1:
                nns -= 1
            if a[i][j] > nns:
                ws('NO')
                return

    for i in range(n):
        for j in range(m):
            nns = 4
            if i == 0 or i == n-1:
                nns -= 1
            if j == 0 or j == m-1:
                nns -= 1
            a[i][j] = nns

    ws('YES')
    for i in range(n):
        wia(a[i])


def main():
    for _ in range(ri()):
        n, m = ria()
        a = [[] for i in range(n)]
        for i in range(n):
            a[i] = ria()

        solve(n, m, a)


if __name__ == '__main__':
    main()
