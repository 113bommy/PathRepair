import itertools
import re
import math
import getpass
import sys
import string

debug = getpass.getuser() == 'frohe'
files = True

if debug and files:
    sys.stdin = open('test.in')
else:
    pass
    # sys.stdin = open('schools.in')
    # sys.stdout = open('schools.out', 'w')


def ria():
    return [int(i) for i in input().split()]

n=ria()[0]
ar = []
for i in range(1, 30):
    ar.append(int('1' * i + '0' * (i - 1),2))
#print(ar)
for i in reversed(ar):
    if n%i==0:
        print(i)
        exit(0)
