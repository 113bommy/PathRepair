# Author Kmoussai 
import sys
import math
import random

if len(sys.argv) >= 2:
    if sys.argv[1] == 'LOCAL':
        sys.stdin = open('input.in', 'r')


n = int(input())
l = map(int, input().split())
l = sorted(l)
mex = 1
for i in l:
    if i >= mex:
        mex += 1
print(mex)
