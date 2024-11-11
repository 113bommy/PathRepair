from sys import stdout
from sys import stdin
def get():
    return stdin.readline().strip()
def getf():
    return [int(i) for i in get().split()]
def put(a, end = "\n"):
    stdout.write(str(a) + end)
def putf(a, sep = " ", end = "\n"):
    stdout.write(sep.join([str(i) for i in a]) + end)

from collections import defaultdict as dd
d = dd(set)
def rec(s, cur, lmt, k):
    if(cur + k <= lmt):
        rec(s + "W" * k, cur + k, lmt, k)
    if(cur + 1 <= lmt):
        rec(s + "R", cur + 1, lmt, k)
    if(cur == lmt):
        global d
        d[lmt].add(s)

def bruh():
    t, k = getf()
    lmt = 10 ** 5 + 1
    fn = [1] * (lmt)
    fn[k] = 2
    for i in range(k + 1, lmt):
        fn[i] = (fn[i - 1] + fn[i - 0 - k]) % (10 ** 9 + 7)
    rs = [0] * lmt
    rs[0] = fn[0]
    #print(fn)
    for i in range(1, lmt):
        rs[i] = (rs[i -  1] + fn[i]) % (10 ** 9 + 7)
    #print(fn)
    #print(rs)
    for i in range(t):
        a, b = getf()
        r = rs[b] - rs[a - 1]
        if(r < 0):
            r += (10 ** 9 + 7)
        put(r)
bruh()
