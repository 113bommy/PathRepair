#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <13/May/2019 04:46:07 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n = int(input())
    arr = get_array()
    from collections import Counter
    d = Counter(arr)
    ans = ['A'] * n
    f = 0
    cnt = 0
    check = 0
    for i in d:
        if d[i] > 2:
            check = 1
        elif d[i] == 1:
            cnt += 1

    if cnt % 2 == 0:
        for i in range(n):
            if d[arr[i]] == 1:
                if f == 0:
                    ans[i] == 'A'
                else:
                    ans[i] = 'B'
                f = 1 - f
        print('YES')
        print(*ans, sep='')
        return

    if cnt % 2 == 1 and check == 0:
        print('NO')
        return

    for i in range(n):
        if d[arr[i]] == 1:
            if f == 0:
                ans[i] = 'A'
            else:
                ans[i] = 'B'
            f = 1 - f
        if check == 1 and d[arr[i]] > 2:
            ans[i] = 'B'
            check = 0
    print('YES')
    print(*ans, sep='')


if __name__ == "__main__":
    main()
