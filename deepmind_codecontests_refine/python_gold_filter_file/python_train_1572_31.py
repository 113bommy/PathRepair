import sys
import os

def solve(xy):
    n = len(xy) // 2
    xy.sort()

    xspan = xy[n - 1] - xy[0]
    yspan = xy[2 * n - 1] - xy[n]
    result = xspan * yspan

    yspan = xy[2 * n - 1] - xy[0]
    for i in range(n - 1):
        xspan = xy[n + i] - xy[i + 1]
        result = min(result, xspan * yspan)

    return result

def main():
    n = int(input())

    xy = list(map(int, input().split()))

    print(solve(xy))

if __name__ == '__main__':
    main()