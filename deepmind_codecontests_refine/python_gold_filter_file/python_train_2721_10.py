#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <24/Feb/2019 09:14:37 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    p, ne = 0, 0
    for i in arr:
        if i > 0:
            p += 1
        elif i < 0:
            ne += 1
    from math import ceil
    x = ceil(n/2)
    #print(p, ne, x)
    if p < x and ne < x:
        print(0)
    elif p >= x:
        print(1)
    else:
        print(-1)


if __name__ == "__main__":
    main()
