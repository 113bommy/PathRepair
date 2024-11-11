'''
Author: csc
Date: 2021-04-28 12:22:16
LastEditTime: 2021-04-29 12:31:32
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \code_py\ex.py
'''


def solve():
    n = int(input())
    mix, mxx = -100000, 100000
    miy, mxy = -100000, 100000
    for _i in range(n):
        x, y, f1, f2, f3, f4 = map(int, input().split())
        if f1 == 0:
            mix = max(mix, x)
        if f2 == 0:
            mxy = min(mxy, y)
        if f3 == 0:
            mxx = min(mxx, x)
        if f4 == 0:
            miy = max(miy, y)
    if mix <= mxx and miy <= mxy:
        print(1, mix, miy)
    else:
        print(0)


def main():
    _ = int(input())
    while _:
        solve()
        _ -= 1


if __name__ == '__main__':
    main()
