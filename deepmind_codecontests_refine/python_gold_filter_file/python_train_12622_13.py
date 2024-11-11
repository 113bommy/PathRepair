import math
import sys
from sys import stdin
input=sys.stdin.readline
for _ in range(int(input())):
    x1,y1,x2,y2=[int(j) for j in input().split()]
    if x1==x2 or y1==y2:
        print(1)
    else:
        print(abs(x1-x2)*abs(y1-y2)+1)