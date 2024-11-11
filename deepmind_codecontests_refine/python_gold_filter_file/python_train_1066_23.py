import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')


def overlapping(a, b):
    return min(a[1], b[1]) - max(a[0], b[0]) >= 0


def overlap(a, b):
    return min(a[0], b[0]), max(a[1], b[1])


def solve(n, x, m, ops):
    i = 0
    while i < m and (x < ops[i][0] or x > ops[i][1]):
        i += 1
    if i >= m:
        return 1

    s = ops[i]
    for j in range(i+1, m):
        if overlapping(s, ops[j]):
            s = overlap(s, ops[j])
    return s[1]-s[0]+1


def main():
    for _ in range(ri()):
        n, x, m = ria()
        ops = []
        for _ in range(m):
            ops.append(tuple(ria()))
        wi(solve(n, x, m, ops))


if __name__ == '__main__':
    main()
