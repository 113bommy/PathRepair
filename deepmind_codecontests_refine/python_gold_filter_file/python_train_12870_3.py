import math
import sys
import getpass
import bisect


def ria():
    return [int(i) for i in input().split()]


files = True

if getpass.getuser().lower() == 'frohenk' and files:
    sys.stdin = open('test.in')
    # sys.stdout = open('test.out', 'w')

n, x, k = ria()
ar = ria()
ar = sorted(ar)
suma=0
for i in ar:

    l = math.ceil(i / x) * x+x * (k-1)
    r = math.ceil(i / x) * x + x * k - 1
    #print(l,r)
    if k == 0:
        l = i
        r = math.ceil(i / x) * x + x * k - 1
    #print(l, r)
    suma-=(bisect.bisect_left(ar, l)- bisect.bisect_right(ar, r))
print(suma)
sys.stdout.close()
