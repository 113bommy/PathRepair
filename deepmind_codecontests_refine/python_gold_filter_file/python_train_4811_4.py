#!/usr/bin/env python3
import sys
input = sys.stdin.readline
 
n, k = [int(item) for item in input().split()]
s = input().rstrip()
s = [int(item) for item in s]
 
loose_from = -1 
for i, item in enumerate(s):
    if i - k < 0:
        continue
    if item > s[i-k]:
        loose_from = k - 1
        break
    elif item < s[i-k]: 
        loose_from = i
        break
if loose_from == -1:
    print(len(s))
    print("".join([str(item) for item in s]))
    exit()
while loose_from >= 0 and s[loose_from] == 9:
    loose_from -= 1
if loose_from - k >= 0:
    s[loose_from] = s[loose_from-k]
else:
    s[loose_from] += 1
for i in range(loose_from+1, n):
    if i - k < 0:
        s[i] = 0
    else:
        s[i] = s[i-k] 
 
print(len(s))
print("".join([str(item) for item in s]))