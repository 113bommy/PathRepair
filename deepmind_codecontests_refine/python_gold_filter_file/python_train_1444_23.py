import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    s = int(readline())

    if s > n:
        print(-1)
        sys.exit()
    if s == n:
        print(n + 1)
        sys.exit()

    for i in range(2, n):
        k = i ** 2
        if k > n:
            break
        x = n
        cur = 0
        while x > 0:
            cur += x % i
            x = x // i

        if cur == s:
            print(i)
            sys.exit()

    ans = INF
    for i in range(1, n):
        k = i ** 2
        if k >= n:
            break
        if (n - s) % i == 0:
            b = (n-s) // i + 1
            p = n // b
            q = n % b
            if p + q == s:
                ans = min(ans,b)

    if ans == INF:
        print(-1)
    else:
        print(ans)


if __name__ == '__main__':
    main()
