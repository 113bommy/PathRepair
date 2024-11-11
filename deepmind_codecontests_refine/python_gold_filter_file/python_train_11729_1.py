#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import sys


def main():
    n = int(sys.stdin.readline())
    player = ['Kuro', 'Shiro', 'Katie']
    l = list(map(str.strip,sys.stdin.readlines()))
    lw = len(l[0])
    m = list(
            map(
                lambda x:max(
                    [x.count(e) for e in set(x)]
                    )
                ,l
                )
            )
    if n == 1:
        for i in range(3):
            if m[i] == lw:
                m[i] -= 2

    winner = []
    for i in range(3):
        if m[i] == max(m) or m[i] +n >= lw:
            winner.append(player[i])

    print(winner[0] if len(winner) == 1 else "Draw")

main()
