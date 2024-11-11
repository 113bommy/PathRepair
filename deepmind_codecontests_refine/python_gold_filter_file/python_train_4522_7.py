#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

def tot():
    s = input()
    return ord(s[0]) - ord('a') + 1, int(s[1])

x0, y0 = tot()
x1, y1 = tot()
print(max(abs(x1 - x0), abs(y1 - y0)))
while x0 != x1 or y0 != y1:
    if x1 > x0 and y1 > y0:
        x0 += 1
        y0 += 1
        print('RU')
    elif x1 < x0 and y1 > y0:
        x0 -= 1
        y0 += 1
        print('LU')
    elif x1 < x0 and y1 < y0:
        x0 -= 1
        y0 -= 1
        print('LD')
    elif x1 > x0 and y1 < y0:
        x0 += 1
        y0 -= 1
        print('RD')
    elif x1 > x0:
        x0 += 1
        print('R')
    elif x1 < x0:
        x0 -= 1
        print('L')
    elif y1 > y0:
        y0 += 1
        print('U')
    else:
        y0 -= 1
        print('D')
