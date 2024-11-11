from math import *
from random import *
def compr(mas):
    n = len(mas)
    mn = []
    mx = []
    cr = [mas[0]]
    for i in range(1, n):
        if mas[i] > mas[i - 1]:
            cr.append(mas[i])
        else:
            mn.append(cr[0])
            mx.append(cr[-1])
            cr = [mas[i]]
    if len(cr) > 0:
        mn.append(cr[0])
        mx.append(cr[-1])
    return mn[:-1:1] + [mx[-1]]
for t in range(int(input())):
    n = int(input())
    mass = list(map(int, input().split()))
    cr = [mass[0]]
    for i in range(1, n):
        if mass[i] > cr[0]:
            cr = [cr[0]]
        else:
            cr.append(mass[i])
    if len(cr) == 1:
        print("YES")
    else:
        print("NO")