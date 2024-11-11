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
    n = inp()
    home = [0]*n
    away = [0]*n
    for i in range(n):
        a = inlt()
        home[i] = a[0]
        away[i] = a[1]
    homeset = set(home)
    awayset = set(away)
    intersection = homeset.intersection(awayset)
    games = 0
    for i in intersection:
        games += home.count(i) * away.count(i)
    print(games)
