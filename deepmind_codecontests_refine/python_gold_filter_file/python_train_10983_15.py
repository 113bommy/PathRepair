#!/usr/bin/python
import sys

upC = 0
downC = 0
for l in sys.stdin:
    for k in l:
        if (k == k.upper()):
            upC = upC + 1
        else:
            downC = downC + 1
    upC = upC - 1
    if (upC > downC):
        print(l.upper().strip())
    else:
        print(l.lower().strip())
    break
