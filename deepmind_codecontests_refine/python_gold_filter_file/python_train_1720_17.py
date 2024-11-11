import sys
# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')


def main():
    n = int(input())
    tl, tr = 0, n
    while tr - tl > 1:
        tm = tl + (tr - tl) // 2
        s = (1 + tm) * tm // 2
        if s >= n:
            tr = tm
        else:
            tl = tm
    s = (1 + tr) * tr // 2
    s -= tr
    n -= s
    print(n)

main()