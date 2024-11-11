#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    dic = {}
    n = int(input())
    if n == 0:
        break

    for i in range(n):
        key, value = input().split()
        dic[key] = value

    ret = ''

    m = int(input())
    for i in range(m):
        s = input().strip()
        ret += dic.get(s, s)

    print(ret)