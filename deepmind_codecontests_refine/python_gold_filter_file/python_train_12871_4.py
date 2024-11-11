#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/10/20 13:52
# @Author  : litianshuang
# @Email   : litianshuang@jingdata.com
# @File    : test.py
# @Desc    :


if __name__== "__main__":
    n, m = [int(n) for n in input().split(' ')]
    w = 100003
    edges = []
    edges.append([1, n, 2])
    st = 2
    if n > 2:
        st = w
        edges.append([1, 2, w - n + 1])
        for  i in range(3, n):
            edges.append([1, i, 1])
    start = 2
    end = 3
    while len(edges) < m:
        if end > n:
            start += 1
            end = start + 1
            continue
        edges.append([start, end, w + 1])
        end += 1
    print(2, st)
    for e in edges:
        print(e[0], e[1], e[2])

