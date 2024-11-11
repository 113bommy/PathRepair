#!/usr/bin/env python3
from math import *


def ri():
    return map(int, input().split())

b, q, l, m  = ri()

a = list(ri())
ans = 0
if abs(b) <= l:
    if not b in a:
        ans+=1
else:
    print(0)
    exit()

i = 0
while True:
    i += 1
    b = b*q
    if b in a:
        pass
    elif abs(b) <= l:
        ans+=1
    else:
        print(ans)
        break

    if i > 10:
        if b == b*q*q or b == b*q:
            if b in a and b*q in a:
                print(ans)
                exit()
            else:
                print("inf")
                exit()