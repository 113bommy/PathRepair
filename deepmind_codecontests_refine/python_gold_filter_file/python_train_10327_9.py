#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

k = int(input())
while k:
    k -= 1
    n = int(input())
    s = input()
    t = input()

    rec_s = [None, 0]
    rec_t = [None, 0]
    ans = "YES"
    for i in range(n):
        if s[i] == t[i]:
            continue
        if rec_s[0] is None and rec_t[0] is None:
            rec_s[0] = s[i]
            rec_s[1] += 1
            rec_t[0] = t[i]
            rec_t[1] += 1
            continue
        if rec_s[0] == s[i] and rec_t[0] == t[i] and rec_s[1] == 1 and rec_t[1] == 1:
            rec_s[1] += 1
            rec_t[1] += 1
            continue
        ans = "NO"
        break
    if rec_s[1] != 2 or rec_t[1] != 2:
        ans = "NO"
    print(ans)
