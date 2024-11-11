#!/usr/bin/env python3
'''
__author__ = 'cinis_de_magma'
https://codeforces.com/contest/1265/problem/A
Thu 05 Dec 2019 11:44:20 PM IST
'''


def soln() -> None:
    '''Solution'''
    def logic() -> None:
        '''Logic'''

        arr = list(input())
        if len(arr) == 1:
            if arr[0] != '?':
                print(arr[0])
            else:
                print('a')
                return

        for i in range(0, len(arr) - 1):
            if arr[i] == '?':
                continue

            if arr[i] == arr[i + 1]:
                print(-1)
                return

        if arr[0] == '?':
            if arr[1] != 'a':
                arr[0] = 'a'
            else:
                arr[0] = 'b'

        for i in range(1, len(arr) - 1):
            if arr[i] == '?':
                if arr[i + 1] == '?':
                    x = chr(ord(arr[i - 1]) + 1)
                    if x == 'd':
                        arr[i] = 'a'
                    else:
                        arr[i] = x
                else:
                    x = chr(ord(arr[i - 1]) + 1)
                    if x == 'd':
                        x = 'a'

                    if x == arr[i + 1]:
                        x = chr(ord(x) + 1)
                        if x == 'd':
                            x = 'a'
                        arr[i] = x
                    else:
                        arr[i] = x

        n = len(arr)
        if arr[n - 1] == '?':
            x = chr(ord(arr[n - 2]) + 1)
            if x == 'd':
                x = 'a'
            arr[n - 1] = x

        print(''.join(arr))

    for _ in range(int(input())):
        logic()


if __name__ == '__main__':
    soln()
