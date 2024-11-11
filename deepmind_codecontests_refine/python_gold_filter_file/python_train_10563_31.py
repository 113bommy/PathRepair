#!/usr/bin/env python3

n, m = [int(i) for i in input().split()]

dic = {}
for i in range(m):
    a, b = input().split()
    dic[a] = b

c = [s for s in input().split()]

for i in range(n):
    s = c[i]
    t = dic[s]
    if len(s) <= len(t):
        print(s, end=" ")
    else:
        print(t, end=" ")
print()
