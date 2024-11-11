#!/usr/bin/env python3
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = [int(item) for item in list(input().rstrip())]
    t = [int(item) for item in list(input().rstrip())]
    s.reverse()
    t.reverse()
    ans = []
    for i, ti in enumerate(t[:-1]):
        si = s[i]
        if ti == si:
            continue
        if ti == s[-1]:
            ans.append(1)
            s[-1] = 1 - s[-1]
        ans.append(n-i)
        tmp = []
        for item in s[i:]:
            tmp.append(1 - item)
        tmp.reverse()
        s = s[:i] + tmp
    if s[-1] != t[-1]:
        ans.append(1)
    if not ans:
        print(0)
    else:
        print(len(ans), *ans)