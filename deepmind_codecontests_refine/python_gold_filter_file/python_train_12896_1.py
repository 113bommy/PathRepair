# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0176

"""
import sys
from sys import stdin
from collections import namedtuple
from math import sqrt
input = stdin.readline


color = namedtuple('color', ['name', 'r', 'g', 'b'])
def main(args):
    references = [color('black',   0x00, 0x00, 0x00), color('blue', 0x00, 0x00, 0xff), color('lime',    0x00, 0xff, 0x00),
                  color('aqua',    0x00, 0xff, 0xff), color('red',  0xff, 0x00, 0x00), color('fuchsia', 0xff, 0x00, 0xff),
                  color('yellow', 0xff, 0xff, 0x00), color('white', 0xff, 0xff, 0xff)]

    while True:
        data = input().strip()
        if data[0] == '0':
            break
        my_r = int(data[1:3], 16)
        my_g = int(data[3:5], 16)
        my_b = int(data[5:7], 16)

        distances = []
        for c in references:
            d = sqrt((c.r - my_r)**2 + (c.g - my_g)**2 + (c.b - my_b)**2)
            distances.append(d)

        closest_distance = min(distances)
        closest_color = distances.index(closest_distance)
        print(references[closest_color].name)


if __name__ == '__main__':
    main(sys.argv[1:])