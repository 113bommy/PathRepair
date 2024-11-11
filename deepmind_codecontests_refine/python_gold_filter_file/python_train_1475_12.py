#!/usr/bin/python
# -*- coding: utf-8 -*-

if __name__ == "__main__":
    n  = int(input())
    a = list(map(int, input().split()))
    a.sort()
    idx = 0
    max_day = 1
    while (idx < n):
        idx += 1
        if (idx<n):
            if a[idx]>=max_day+1:
                max_day += 1
    print(max_day)