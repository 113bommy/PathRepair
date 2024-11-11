import sys
import collections
import math
import heapq
from operator import itemgetter

def getint():
    return int(input())

def getints():
    return [int(x) for x in input().split(' ')]

n = getint()
s = input()

result = 0

sumCount = 0
minDelta = 0

for char in s:
    if char == '-':
        sumCount -= 1
    else:
        sumCount += 1
    if sumCount < 0:
        minDelta = max(minDelta, -sumCount)

result = max(0, sumCount + minDelta)
print(str(result))