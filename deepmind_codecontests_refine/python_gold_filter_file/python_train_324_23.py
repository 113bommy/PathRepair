#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Mar/2019 07:55:31 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


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
    odd = []
    even = []
    arr.sort()
    for i in arr:
        if i % 2 == 0:
            even.append(i)
        else:
            odd.append(i)
    # print(odd)
    # print(even)

    i = len(odd)
    j = len(even)
    #moves = 0
    while i > 0 and j > 0:
        odd.pop()
        even.pop()
        i -= 1
        j -= 1
        #moves += 1
    if (len(odd) != 0):
        odd.pop()
    elif (len(even) != 0):
        even.pop()
    print(sum(odd)+sum(even))


if __name__ == "__main__":
    main()
