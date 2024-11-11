#!/usr/bin/env python
# -*- coding: utf-8 -*-


def solve():
    n, m = map(int, input().split())
    s, t = input().strip(), input().strip()
    if s.find("*") >= 0:
        ai = s.find("*")
        if t.find(s[:ai]) != 0:
            print("NO")
            return
        if ai == n - 1:
            print("YES")
        else:
            t2 = t[ai:]
            i2 = t2.rfind(s[ai + 1:])
            print("YES" if 0 <= i2 and t2[i2:] == s[ai + 1:] else "NO")
    else:
        print("YES" if s == t else "NO")


if __name__ == "__main__":
    solve()
