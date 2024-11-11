#!/usr/bin/pypy3
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    cpd = c / b
    if c <= a:
        print(-1, b)
    elif cpd >= a:
        print(1, -1)
    elif cpd < a:
        print(1, b)
