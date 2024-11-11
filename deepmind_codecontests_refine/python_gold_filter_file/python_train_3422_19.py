#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys
import math

for s in sys.stdin:
    for i in range(26):
        state = list(s.strip())
        j = 0
        for d in state:
            if 'a' <= d and d <= 'z':
                state[j] = chr((ord(d) + i - ord('a')) % 26 + ord('a'))
            elif 'A' <= d and d <= 'Z':
                state[j] = chr((ord(d) + i - ord('A')) % 26 + ord('A'))
            j += 1

        state = "".join(state)

        if "the" in state or "this" in state or "that" in state:
            print(state)
            break