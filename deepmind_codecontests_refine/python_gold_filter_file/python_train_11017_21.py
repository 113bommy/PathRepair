import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    a = list(map(int, readline().split()))
    b = list(map(abs, a))
    idx = b.index(max(b))

    res = []
    for i, x in enumerate(a):
        a[i] += a[idx]
        res.append((idx + 1, i + 1))

    if a[idx] > 0:
        for i in range(1, n):
            if a[i - 1] > a[i]:
                a[i] += a[i - 1]
                res.append((i, i + 1))
    elif a[idx] < 0:
        for i in range(n - 2, -1, -1):
            if a[i] > a[i + 1]:
                a[i] += a[i + 1]
                res.append((i + 2, i + 1))

    print(len(res))
    for x, y in res:
        print(x, y)


if __name__ == '__main__':
    main()
