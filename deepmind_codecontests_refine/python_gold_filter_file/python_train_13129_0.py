#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def nbCoups(n,x,y,d):
    if (x - y) % d == 0:
        return abs(x-y)//d
    if (y - 1) % d != 0 and (n - y) % d != 0:
        return -1
    if (y - 1) % d == 0:
        coups_gauche = (x - 2) // d + 1 + (y - 1) // d
        if (n - y) % d != 0:
            return coups_gauche
        coups_droit = (n - y) // d + (n - x - 1) // d + 1
        return min(coups_gauche,coups_droit)
    else:
        return (n - y) // d + (n - x - 1) // d + 1

t = int(input())
for i in range(t):
    n,x,y,d = [int(x) for x in input().split(' ')]
    print(nbCoups(n,x,y,d))