import sys
#import math
#from collections import deque

input = sys.stdin.readline

def getAns(k):
    r = 0
    l = 0
    u = 0
    d = 0

    for i in k:
        if i == 'D': d += 1
        elif i == 'U': u += 1
        elif i == 'R': r += 1
        elif i == 'L': l += 1

    r = min(r, l)
    u = min(u, d)
    if r == 0 or u == 0:
        if r == 0 and u == 0:
            sys.stdout.write('0\n')
        elif r == 0:
            sys.stdout.write('2\n')
            sys.stdout.write('UD')
        else:
            sys.stdout.write('2\n')
            sys.stdout.write('LR')
    else:
        sys.stdout.write(str(2 * r + 2 * u) + '\n')
        for i in range(r):
            sys.stdout.write('R')
        for i in range(u):
            sys.stdout.write('U')
        for i in range(r):
            sys.stdout.write('L')
        for i in range(u):
            sys.stdout.write('D')

        
n = int(input())

for i in range(n):
    getAns(list(input()))
    if not i == n - 1:
        sys.stdout.write('\n')