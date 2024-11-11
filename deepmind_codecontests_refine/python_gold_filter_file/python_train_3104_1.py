import sys
from bisect import bisect_left

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    if len(A) != len(set(A)) or len(B) != len(set(B)):
        print(0)
        exit()
    A.sort()
    B.sort()
    As = set(A)
    Bs = set(B)
    res = 1
    for x in reversed(range(1, n * m + 1)):
        if x in As and x in Bs:
            continue
        elif x in As:
            res *= m - bisect_left(B, x)
        elif x in Bs:
            res *= n - bisect_left(A, x)
        else:
            s = m - bisect_left(B, x)
            t = n - bisect_left(A, x)
            res *= s * t - (n * m - x)
        res %= mod
    print(res)


if __name__ == '__main__':
    resolve()
