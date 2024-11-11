# -*- coding: utf-8 -*-
# @Time    : 2019/5/1 23:27
# @Author  : LunaFire
# @Email   : gilgemesh2012@gmail.com
# @File    : C. Match Points.py


def main():
    n, z = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    left, right, ret = 0, n // 2, 0
    while left <= right:
        mid = (left + right) // 2
        flag = True
        for i in range(mid):
            if a[n - mid + i] - a[i] < z:
                flag = False
                break
        if flag:
            left = mid + 1
            ret = max(ret, mid)
        else:
            right = mid - 1
    print(ret)


if __name__ == '__main__':
    main()
