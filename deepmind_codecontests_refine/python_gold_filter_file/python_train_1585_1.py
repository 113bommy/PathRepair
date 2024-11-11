#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb  2 15:05:04 2020

@author: dennis
"""

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

for _ in range(int(input())):
    n = int(input())
    s = ''.join([x for x in input() if x in {'1', '3', '5', '7', '9'}])
    if len(s) > 1:
        print(s[:2])
    else:
        print(-1)
