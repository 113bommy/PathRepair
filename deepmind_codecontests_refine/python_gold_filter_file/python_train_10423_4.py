#!/bin/python3

# Created by Dipta Das on 01-12-2018
# Title:
# Problem Link:
# Editorial:
# Source Code:
# Comments:

import math
import os
import random
import re
import sys

n = int(input())
string = str(input())

left = [0]*(n+1)
right = [0]*(n+1)

for i in range (n):
    if (string[i] == 'G'):
        left[i] = 1;
        if (i > 0):
            left[i] += left[i-1]

for i in range(n-1, -1, -1):
    if (string[i] == 'G'):
        right[i] = 1;
        if (i < n-1): right[i] += right[i+1]

total = 0
ans = 0
for char in string:
    if (char == 'G'): total += 1

for i in range (n):
    if string[i] == 'G': continue
    newans = 1
    if (i > 0): newans += left[i-1]
    if (i < n-1): newans += right[i+1]
    ans = max(newans, ans)


ans = min(ans, total)
if (n == total): ans = total

print(ans)




