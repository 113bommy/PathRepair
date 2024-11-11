#!/usr/bin/python
import sys

n = 0
p = 1
num = 0
cur = 0
for l in sys.stdin:
    if n == 0:
        iterations = int(l.strip())
        n = n + 1
    else:
        l = int(l.strip())
        if (p <= iterations):
            p = p + 1
            if (cur != l):
                num = num + 1
                cur = l
        else:
            break

print(num)
