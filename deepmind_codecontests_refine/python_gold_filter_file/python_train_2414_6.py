'''
    Author : thekushalghosh
    Team   : CodeDiggers
'''
import sys,math,statistics as ss,collections as cc
input = sys.stdin.readline
n = int(input())
a = input()
a = a[:len(a) - 1]
if len(a) % n == 0:
    q = a[:n] * (len(a) // n)
    if q > a:
        print(q)
    elif a[:n].count("9") == n:
        print("".join((["1"] + (["0" * (n - 1)])) * ((len(a) + n) // n)))
    else:
        print(str(int(a[:n]) + 1) * (len(a) // n))
else:
    print("".join((["1"] + (["0" * (n - 1)])) * math.ceil(len(a) / n)))