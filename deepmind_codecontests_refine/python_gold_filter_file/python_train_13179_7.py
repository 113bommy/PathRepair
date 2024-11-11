#!/usr/bin/env python
import sys


def do(a, m):
    for x in range(a[0]):
        for y in range(a[0]):
            if m[y][x] != 1:

                for xx in range(a[0]):
                    for yy in range(a[0]):
                        if xx == x or yy == y:
                            continue
                        if m[y][x] == m[yy][x] + m[y][xx]:
                            break
                    else:
                        continue

                    break
                else:
                    print('No')
                    return

    print('Yes')


def main():
    a = list(map(int, input().split()))
    m = [list(map(int, input().split())) for i in range(a[0])]
    do(a, m)


if __name__ == '__main__':
    main()
