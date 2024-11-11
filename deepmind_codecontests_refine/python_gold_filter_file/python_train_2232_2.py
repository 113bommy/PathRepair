#!/usr/bin/env python3
import sys
input = sys.stdin.readline

############ ---- Input Functions, coutery of 'thekushalghosh' ---- ############


def inp():
    return(int(input()))


def inlt():
    return(list(map(int, input().split())))


def insr():
    s = input()
    return(list(s[:len(s) - 1]))


def invr():
    return(map(int, input().split()))


if __name__ == "__main__":
    calories = inlt()
    game = insr()
    game = [int(g) for g in game]
    total = 0
    for g in game:
        if g == 1:
            total += calories[0]
        if g == 2:
            total += calories[1]
        if g == 3:
            total += calories[2]
        if g == 4:
            total += calories[3]
    print(total)
