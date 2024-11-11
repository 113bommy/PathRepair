#!/usr/bin/env python

def test_case():
    n, T = map(int, input().split())
    arr = list(map(int, input().split()))
    s = ""
    flag = 0
    white = set()
    black = set()
    for a in arr:
        if (T%2 == 0) and (a == T//2):
            if flag == 1:
                s += "0 "
                flag = 0
            else:
                s += "1 "
                flag = 1
        else:
            if a in white:
                s += "1 "
            elif a in black:
                s += "0 "
            elif (T-a) in white:
                black.add(a)
                s += "0 "
            else:
                white.add(a)
                s += "1 "
    print(s.strip())

def main():
    cases = int(input())
    for _ in range(cases):
        test_case()

main()
