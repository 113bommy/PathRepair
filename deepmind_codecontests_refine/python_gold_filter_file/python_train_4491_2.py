import sys
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import *
from time import time
from io import StringIO as stream 
from atexit import register

def sync_with_stdio(sync=True):
    global input, flush

    if sync:
        flush = sys.stdout.flush
    else:
        sys.stdin = stream(sys.stdin.read())
        input = lambda: sys.stdin.readline().rstrip('\r\n')

        #sys.stdout = stream()
        #register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))

sync_with_stdio(False)
#input = sys.stdin.readline
#print = sys.stdout.write
n, = I()
w = 0
h = 0
while n:
    n -= 1
    c, x, y = input().split()
    x = int(x)
    y = int(y)
    if c == '+':
        if y > x: x, y = y , x
        w = max(w, x)
        h = max(h, y)
    else:
        if (x >= w and y >= h) or (y >= w and x >= h):
            print('YES')
        else:
            print('NO')