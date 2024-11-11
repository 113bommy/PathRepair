#!/usr/bin/env python
# coding=utf-8

input_s = int(input())
mount = 0
for i in range(input_s):
    input_l = input().split(' ')
    if int(input_l[1]) - int(input_l[0]) >= 2:
        mount += 1
print(mount)
