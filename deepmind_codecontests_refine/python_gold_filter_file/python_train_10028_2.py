import sys
from os import path
import collections
from collections import defaultdict
import math

if path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
test = int(sys.stdin.readline().rstrip())
p = -1
while test > 0:
    test -= 1
    n = int(sys.stdin.readline().rstrip())
    i = 1
    if n == 1:
        print(i)
    else:
        s = c = 0
        while s < n:
            c += 1
            s += i
            i += 2
        print(c)
