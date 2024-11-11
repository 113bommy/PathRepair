# http://codeforces.com/problemset/problem/399/A

import sys


def main():
    n, p, k = [int(v) for v in sys.stdin.readline().split()]
    s = []
    if p - k > 1:
        s.append('<<')
    for i in range(p - k, p + k + 1):
        if i >= 1 and i <= n:
            if i == p:
                s.append('(' + str(i) + ')')
            else:
                s.append(str(i))
    if p + k < n:
        s.append('>>')

    print(' '.join(s))


if __name__ == '__main__':
    main()