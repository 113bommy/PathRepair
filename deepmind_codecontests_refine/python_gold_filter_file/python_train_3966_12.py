# -*- coding: utf-8 -*-
"""
Created on Fri Jul  6 02:18:34 2018

@author: Arsanuos
"""

import math as m

def main():
    rd = lambda: list(map(int, input().split()))
    n, m = rd()
    seg = []
    for i in range(m):
        seg.append(rd())
    print("01" * int(n/2), end="")
    if int(n/2) != n/2:
        print('0')


if __name__ == "__main__":
    main()