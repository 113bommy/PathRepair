#from random import random, randint
from sys import stdout, stdin
import math

#n, k = map(int, input().split())
n = int(input())
text = stdin.read()
a, b, c = [[], [], []]
d = {i: [] for i in range(1, 8)}
if  (not "A" in text) or (not "B" in text) or (not "C" in text):
    print(-1)
else:
    l = text.split('\n')
    for z in l:
        try:
            c, t = z.split()
            d[4*("A" in t)+2*("B" in t)+("C" in t)].append(int(c))
        except:
            continue

    p = {k: (min(l) if l else 333333) for k, l in d.items()}
    print(min(
        p[7],
        min(p[1], p[3], p[5]) + p[6],
        min(p[2], p[3], p[6]) + p[5],
        min(p[4], p[5], p[6]) + p[3],
        min(p[1], p[3], p[5]) + min(p[2], p[3], p[6]) + min(p[4], p[6], p[5]), 
    ))
