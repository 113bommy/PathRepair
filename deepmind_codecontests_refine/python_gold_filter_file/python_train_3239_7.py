import math
import random
import sys
import collections


def In():
    return map(int, sys.stdin.readline().split())


input = sys.stdin.readline


#
# l = [1200,1300,1400,1500,1600,1700]
# print(random.choice(l))

def isoedge():
    v, e = In()
    pos = -1
    while True:
        if pos * (pos + 1) // 2 >= e:
            maxiso = v - pos-1
            break
        pos += 1
    print(max(v - (2 * e), 0), maxiso)


isoedge()
