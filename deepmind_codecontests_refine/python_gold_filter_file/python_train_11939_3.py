#!/usr/bin/env python3
from sys import stdin, stdout

def rint():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()


n, p = rint()

s = input()
s = list(s)

flag = 0
for i in range(n-p):
    j = i+p
    if s[i] == s[j] and s[i] != '.':
        pass
    else:
        flag = 1

if flag == 0:
    print("No")
    exit()


for i in range(n-p):
    j = i+p
    if s[i] == s[j] and s[i] == '.':
        # enter . with different value
        for k in range(n):
            if k == i:
                s[k] = "1"
            elif k == j:
                s[k] = "0"
            elif s[k] == ".":
                s[k] = "1"
        print("".join(s))
        exit()

    if s[i] != s[j]:
        #enter arbitary value with .
        if s[i] == ".":
            if s[j] == "0":
                s[i] = "1"
            else:
                s[i] = "0"
        if s[j] == ".":
            if s[i] == "0":
                s[j] = "1"
            else:
                s[j] = "0"

        for k in range(n):
            if s[k] == ".":
                s[k] = "1"
        print("".join(s))
        exit()

