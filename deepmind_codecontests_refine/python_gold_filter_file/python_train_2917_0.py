#! /usr/bin/python
# -*- coding:utf-8 -*-
N, W = map(int, input().split())
dp = [0]*(W+1)
max_w = 0
for i in range(N):
    v, w, m = map(int, input().split())
    n = 1
    while m > 0 :
        m -= n
        _v, _w = v*n, w*n
        if max_w + _w > W:
            max_w = W
        else:
            max_w = max_w + _w
        for k in range(max_w, _w-1, -1):
            if dp[k] < dp[k-_w] + _v:
                dp[k] = dp[k-_w] + _v
        if n*2>m:
            n = m
        else:
            n = 2*n

print(max(dp))


