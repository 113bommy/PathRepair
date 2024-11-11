'''
    Python3(PyPy3) Template for Programming-Contest.
'''

import sys


def input():
    return sys.stdin.readline().rstrip()


DXY = [(0, -1), (1, 0), (0, 1), (-1, 0)]  # LDRU
mod = 998244353
inf = 1 << 64


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        if n % 2 == 0:
            print(n - 3, 2, 1)
        else:
            k = n // 6
            if n % 6 == 1:
                if k % 2 == 0:
                    print(3 * k + 1,3 * k - 1,1)
                else:
                    print(3 * k + 2,3 * k - 2,1)
            elif n % 6 == 3:
                print(4 * k + 1, 2 * k + 1, 1)
            else:
                print(4 * k + 3, 2 * k + 1, 1)
    return 0


if __name__ == "__main__":
    main()
